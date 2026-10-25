-- ovltrace.lua -- runtime owner trace for cross-overlay data words (T3.1 phase 2.4); driven by tools/replay/ovltrace.py.
-- Needs `-interpreter -debugger` (C0104; Read breakpoints need the debugger).
-- Logs every Ovl_Load 80015EB4 call (`redux: load run= frame= idx= dest= size= ra=`; size from the live TOC 800E6188+8*idx)
-- and every new (pc, value, residency) CPU read of a site word (`redux: rd run= frame= pc= site= val= at_site= at_val=`;
-- at_* = overlay index resident at that address per the load log so far, -1 none; T3.1.1.1 appends `b=` (index resident at
-- 800FA000), `ra= sp=`, `base=` (pool j 0..6 of a game_80021A1C dispatcher whose table pointer is scratchpad 1F800080+4j,
-- `sub` = ovl18 func_800EED68_ovl18's `lb 5(s0)` table, `?` other) `idx=` (type byte = (site-table)/4) `obj=` (a0/s0)
-- and `forced=1` when the job has an fspawn). Residency: a load overwrites
-- [dest, dest+size) only; the rest of an earlier load stays resident (a 0x540 data overlay over a stage overlay's head). Sites: `site=<hex>` of each non-`sub=asm` line of REDUX_SITES (no
-- addresses in this file, G12). Values are pointers into overlay RAM, never game bytes.
-- Mode pad: REDUX_PAD set -> tools/replay/replay.lua drives the pad and quits at `end` (run name `pad`).
-- Mode poke: REDUX_STAGES=`s[.u][:b@d],...` (decimal): pad 1 taps START/CROSS every 60 frames (prove_ovl3839.lua); on the
-- REDUX_POKE_HIT-th (default 4, C0109) exec hit of 8001368C (func_80013674's stage read, before its stage==11 g_OvlIdxStageC
-- load at 800FA000 and its g_OvlIdxStageSub[2*stage+sub] load) the stage/sub bytes 800D1C0C/0D are set to s/u; `:b@d`
-- writes b to 800D1C1D (StageC index; func_80013524's StageB[b-2] when it changes) d frames after that poke.
-- `>v@k` (natural sub change, e.g. a data overlay over its stage overlay): k frames after the poke X's HP byte 8009A0FD
-- is zeroed (`kill`), and the next hit of 8001368C sets sub=v (`poke2`).
-- `#v@k` (forced sub change): k frames after the poke sub:=v and game mode 800D1C00:=8 (mode 8 = func_80020CF4: calls
-- func_80013674, then mode 9) so the stage load re-runs with sub=v over the resident sub-0 overlay (`remode`).
-- `!b` (forced StageB): on the first exec of func_800203F0 (mode 9, stage init) after the poke 800D1C1D:=b (`force`), so
-- its gate func_80020F44 (stage==12, 2<=b<10, b != D_800D1598) calls func_80013524 -> g_OvlIdxStageB[b-2] at 800FA000.
-- `+s/m` (ovl18 spawn route, prove_ovl3839.lua, T4): s frames after this job's idx=18 load a free slot of pool 80092090
-- (48 x 9C) is set +0=1 +1=73 +2=0 +4=3 and 800D1C31=0 (`spawn`); once idx 38 has been loaded m frames that slot gets
-- +4=6, +14=slot+98 (`state6`), so ovl18 loads 38 then 39 at 800FA000.
-- `*k.j.T@d~F` (forced call, T3.1.1.1): d frames after overlay k is loaded at 800FA000 a free slot of pool j (table
-- POOLS below: pool/stride/count per dispatcher) is zeroed and set +0=1 +1=T (`fspawn ... site=` table_j+4T). Exec bps at
-- each jalr of that dispatcher (a0 == slot and +1 == T: calls+1, sp noted, first table word read -> `rdsite=`; a0 == slot
-- with another type: `foreign=`, a game object took the slot) and at jalr+8 (sp differs: unbalanced+1), and at 80000080
-- (ExcCode not Int/Syscall: exc+1); F frames later, or on a pause, or at job end: `fcall ... ok|bad` (ok = calls>0, no
-- unbalanced, no exc, no pause). In a `*` job a load at 800FA000 of an index other than 38 retires (+0=0, `retire n=`)
-- the `+s/m` slot and every live object of POOLS whose handler word is >= 800FA000 (its code was just overwritten; the
-- 0x73 route's type-66 child otherwise runs its ovl38 handler over 39 and crashes). Every job with `*` prints one fcall line.
-- `*k.j.T@d~F:<st>` (T3.1.1.1.1, natural spawn state; `;`-separated, all hex): `o=v[.w]` writes v (w = 1|2|4 bytes,
-- default 1) at slot+o (`0=41` overrides the +0 flag); `Po` stores the parent pointer word at slot+o; `Co[.w]` copies w
-- bytes (default 1) of parent+o to slot+o. Parent = first active object of pool 80092090 (`parent=` on the fspawn line,
-- `none`: P/C items skipped). `;` not `,`: `,` separates jobs.
-- `^F[r]:<it>` (forced byte poke, T4.1.1): F frames after the stage poke write each `;`-separated item (all hex, 1 byte):
-- `A=V` at address A; `A.S.N+O=V` at +O of the first free slot (byte 0 == 0) of pool A (stride S, N slots), one slot per
-- pool per job (`fpoke ... slot=`). `r`: re-poke every frame after F. rd lines of such a job carry `forced=1`.
-- REDUX_HOLD=<button>: after the poke hold it and tap CROSS only. After
-- REDUX_FRAMES (default 3000) frames the in-memory savestate taken before that hit (C0106) is reloaded with the load
-- log as it was, and the next job runs. A debugger pause (C0108) skips to the next job, or quits on the last.
-- Listener recycled every 16384 vsyncs (C0107). Exit 0 when all jobs ran; 3 if the poke hit never came (REDUX_MAXBOOT).
local ffi, bit = require('ffi'), require('bit')
local dir = debug.getinfo(1, 'S').source:sub(2):match('^(.*)/')

local TOC, ST, OVL_LOAD, POKE = 0x800E6188, 0x800D1C0C, 0x80015EB4, 0x8001368C
local frames = tonumber(os.getenv('REDUX_FRAMES') or '3000')
local poke_hit = tonumber(os.getenv('REDUX_POKE_HIT') or '4')
local maxboot = tonumber(os.getenv('REDUX_MAXBOOT') or '15000')
local hold = os.getenv('REDUX_HOLD')
local BTN = PCSX.CONSTS.PAD.BUTTON
local pad = PCSX.SIO0.slots[1].pads[1]

local function ram() return ffi.cast('uint8_t*', PCSX.getMemPtr()) end
local function u8(a) return ram()[bit.band(a, 0x1FFFFF)] end
local function u32(a) return ffi.cast('uint32_t*', ram() + bit.band(a, 0x1FFFFC))[0] end

local count, run, loads, seen = 0, 'pad', {}, {}
local ovl18_at, ovl38_at, slot, s6 = nil, nil, nil, nil
local POOL, NSLOT, SLOT, MODE = 0x80092090, 48, 0x9C, 0x800D1C00
-- game_80021A1C dispatchers: j -> pool, stride, count (loop bound / stride), jalr pcs; table pointer at scratchpad SCR+4j
local SCR, B800, SUBLW = 0x1F800080, 0x800FA000, 0x800EEDAC
local POOLS = {
  [0] = { 0x80092090, 0x9C, 48, { 0x80022044 } },             -- func_80021F64
  [1] = { 0x80096D98, 0x9C, 32, { 0x80022290 } },             -- func_800221B0
  [2] = { 0x80094398, 0x70, 96, { 0x80022388 } },             -- func_800222D0
  [3] = { 0x8009E7A0, 0x30, 96, { 0x80022470, 0x800224BC } }, -- func_800223E4
  [4] = { 0x800D1F40, 0x60, 128, { 0x800226D0 } },            -- func_80022618
  [5] = { 0x800C6A10, 0xA4, 64, { 0x800225D8 } },             -- func_800224F8
  [6] = { 0x8009F9A0, 0x60, 64, { 0x800227B8, 0x80022808 } }, -- func_8002272C
}
local LWJ = {}  -- table-read pc (jalr - 8) -> j
for j, p in pairs(POOLS) do for _, pc in ipairs(p[4]) do LWJ[pc - 8] = j end end
local okscr, scrp = pcall(function() return ffi.cast('uint8_t*', PCSX.getScratchPtr()) end)
local function scr32(a) return okscr and ffi.cast('uint32_t*', scrp + bit.band(a, 0x3FC))[0] or 0 end
local kat, kidx = nil, nil  -- frame / index of the last load at 800FA000
local fs, fjob = nil, false -- forced-call state of this job; job has `*`
local pjob = false          -- job has `^`
local function at(a)
  for _, l in ipairs(loads) do if a >= l.lo and a < l.hi then return l.idx end end
  return -1
end
local function copy(t) local c = {} for i, v in ipairs(t) do c[i] = v end return c end

bp_load = PCSX.addBreakpoint(OVL_LOAD, 'Exec', 4, 'ovltrace load', function()
  local r = PCSX.getRegisters().GPR.n
  local idx, dest = r.a0, r.a1
  local size = u32(TOC + 8 * idx + 4)
  local keep = {}
  for _, l in ipairs(loads) do
    if l.lo < dest then keep[#keep + 1] = { idx = l.idx, lo = l.lo, hi = math.min(l.hi, dest) } end
    if l.hi > dest + size then keep[#keep + 1] = { idx = l.idx, lo = math.max(l.lo, dest + size), hi = l.hi } end
  end
  keep[#keep + 1] = { idx = idx, lo = dest, hi = dest + size }
  loads = keep
  print(string.format('redux: load run=%s frame=%d idx=%d dest=%08X size=%X ra=%08X stage/sub=%d/%d',
    run, count, idx, dest, size, r.ra, u8(ST), u8(ST + 1)))
  if dest == B800 then kat, kidx = count, idx end
  if idx == 18 and not ovl18_at then ovl18_at = count end
  if idx == 38 and not ovl38_at then ovl38_at = count end
end)

local nsites = 0
bp_sites = {}
for line in io.lines((assert(os.getenv('REDUX_SITES'), 'REDUX_SITES'))) do
  local s = line:match('site=(%x+)')
  if s and not line:match('sub=asm') then
    local a = tonumber(s, 16)
    if not bp_sites[a] then
      nsites = nsites + 1
      bp_sites[a] = PCSX.addBreakpoint(a, 'Read', 4, 'ovltrace site', function() local okr, e = pcall(function()
        local R = PCSX.getRegisters()
        local pc, g = R.pc, R.GPR.n
        local v = u32(a)
        local s_at, v_at, b = at(a), at(v), at(B800)
        local k = string.format('%s %08X %08X %08X %d %d %d', run, a, pc, v, s_at, v_at, b)
        if seen[k] then return end
        seen[k] = true
        local base, obj = LWJ[pc], g.a0
        if pc == SUBLW then base, obj = 'sub', g.s0 end
        local idx = base == 'sub' and u8(obj + 5) or u8(obj + 1)
        print(string.format('redux: rd run=%s frame=%d pc=%08X site=%08X val=%08X at_site=%d at_val=%d b=%d ra=%08X '
          .. 'sp=%08X base=%s idx=%d obj=%08X forced=%d', run, count, pc, a, v, s_at, v_at, b, g.ra, g.sp,
          tostring(base or '?'), idx, obj, (fjob or pjob) and 1 or 0))
      end) if not okr then print('redux: err rd ' .. tostring(e)) end end)
    end
  end
end
print(string.format('redux: sites %d', nsites))

-- poke mode state
local jobs = {}
for s in (os.getenv('REDUX_STAGES') or ''):gmatch('[^,]+') do
  local st, sub = s:match('^(%d+)%.?(%d*)')
  local b, d = s:match(':(%d+)@(%d+)')
  local v, k = s:match('>(%d+)@(%d+)')
  local mv, mk = s:match('#(%d+)@(%d+)')
  local sp, sm = s:match('%+(%d+)/(%d+)')
  local fk, fj, ft, fd, fF = s:match('%*(%d+)%.(%d+)%.(%d+)@(%d+)~?(%d*)')
  jobs[#jobs + 1] = { st = tonumber(st), sub = tonumber(sub) or 0, b = tonumber(b), d = tonumber(d) or 0,
                      v = tonumber(v), k = tonumber(k), mv = tonumber(mv), mk = tonumber(mk),
                      f = tonumber(s:match('!(%d+)')), sp = tonumber(sp), sm = tonumber(sm), spec = s,
                      fk = tonumber(fk), fj = tonumber(fj), ft = tonumber(ft), fd = tonumber(fd), fF = tonumber(fF),
                      fst = s:match('%*%d+%.%d+%.%d+@%d+~?%d*:([%x=;%.P]+)$') }
  local pf, pr, pit = s:match('%^(%d+)(r?):([%x=;%.%+]+)')
  jobs[#jobs].pf, jobs[#jobs].pr, jobs[#jobs].pit = tonumber(pf), pr == 'r', pit
end
local job, pokes, poked, snap, base, reloaded, killed, forced = 1, 0, nil, nil, nil, nil, nil, nil
local pslots  -- `^` job: pool base -> free slot (false: none), resolved at the first poke

local function quit(code)
  print(string.format('redux: done frame=%d run=%s', count, run))
  PCSX.quit(code)
end
-- forced call outcome (`*`): one fcall line per job, also when the spawn never happened
local function fcall_end(why)
  if not fjob or (fs and fs.done) then return end
  local j = jobs[job]
  if not fs then
    fs = { k = kidx or -1, j = j.fj, t = j.ft, site = 0, calls = 0, unb = 0, exc = 0, bps = {}, foreign = 0 }
    why = 'nospawn-' .. why
  end
  fs.done = true
  for _, bp in ipairs(fs.bps) do bp:remove() end
  if fs.pend then fs.unb = fs.unb + 1 end
  local ok = fs.calls > 0 and fs.unb == 0 and fs.exc == 0 and why ~= 'pause'
  print(string.format('redux: fcall run=%s frame=%d site=%08X k=%d pool=%d type=%d %s calls=%d unbalanced=%d exc=%d '
    .. 'exccode=%d foreign=%d rdsite=%08X end=%s', run, count, fs.site, fs.k, fs.j, fs.t, ok and 'ok' or 'bad', fs.calls,
    fs.unb, fs.exc, fs.code or -1, fs.foreign, fs.rd or 0, why))
end
local function fspawn(j)
  local P = POOLS[j.fj]
  local sl
  for i = 0, P[3] - 1 do
    if u8(P[1] + i * P[2]) == 0 then sl = P[1] + i * P[2] break end
  end
  fs = { k = at(B800), j = j.fj, t = j.ft, site = scr32(SCR + 4 * j.fj) + 4 * j.ft, calls = 0, unb = 0, exc = 0,
         at = count, slot = sl, bps = {}, foreign = 0 }
  local tabs = {}
  for i = 0, 6 do tabs[#tabs + 1] = string.format('%08X', scr32(SCR + 4 * i)) end
  print(string.format('redux: fspawn run=%s frame=%d k=%d pool=%d type=%d slot=%s site=%08X tabs=%s', run, count, fs.k,
    j.fj, j.ft, sl and string.format('%08X', sl) or 'none', fs.site, table.concat(tabs, '/')))
  if not sl then return fcall_end('noslot') end
  local p = ram() + bit.band(sl, 0x1FFFFF)
  ffi.fill(p, P[2], 0)
  p[0], p[1] = 1, j.ft
  if j.fst then  -- natural spawn state (header `:<st>`)
    local par
    for i = 0, NSLOT - 1 do
      if u8(POOL + i * SLOT) ~= 0 then par = POOL + i * SLOT break end
    end
    local function put(q, v, w)
      if w == 4 then ffi.cast('uint32_t*', q)[0] = v elseif w == 2 then ffi.cast('uint16_t*', q)[0] = v else q[0] = v end
    end
    for it in j.fst:gmatch('[^;]+') do
      local o, v, w = it:match('^(%x+)=(%x+)%.?(%d?)$')
      local c, o2, w2 = it:match('^([PC])(%x+)%.?(%d?)$')
      if o then put(p + tonumber(o, 16), tonumber(v, 16), tonumber(w) or 1)
      elseif c == 'P' and par then put(p + tonumber(o2, 16), par, 4)
      elseif c == 'C' and par then
        ffi.copy(p + tonumber(o2, 16), ram() + bit.band(par + tonumber(o2, 16), 0x1FFFFF), tonumber(w2) or 1)
      end
    end
    print(string.format('redux: fstate run=%s frame=%d parent=%s', run, count, par and string.format('%08X', par) or 'none'))
  end
  for _, pc in ipairs(P[4]) do
    fs.bps[#fs.bps + 1] = PCSX.addBreakpoint(pc, 'Exec', 4, 'ovltrace fcall', function()
      local g = PCSX.getRegisters().GPR.n
      if not fs or fs.done or g.a0 ~= fs.slot then return end
      if u8(fs.slot + 1) ~= fs.t then fs.foreign = fs.foreign + 1 return end  -- slot taken over by a game object
      fs.rd = fs.rd or g.v0                                                  -- table word the dispatcher read
      if fs.pend then fs.unb = fs.unb + 1 end
      fs.calls, fs.pend = fs.calls + 1, g.sp
    end)
    fs.bps[#fs.bps + 1] = PCSX.addBreakpoint(pc + 8, 'Exec', 4, 'ovltrace fret', function()
      if not fs or not fs.pend then return end
      if PCSX.getRegisters().GPR.n.sp ~= fs.pend then fs.unb = fs.unb + 1 end
      fs.pend = nil
    end)
  end
  fs.bps[#fs.bps + 1] = PCSX.addBreakpoint(0x80000080, 'Exec', 4, 'ovltrace fexc', function()
    local code = bit.band(bit.rshift(PCSX.getRegisters().CP0.r[13], 2), 0x1F)  -- Cause.ExcCode
    if fs and not fs.done and code ~= 0 and code ~= 8 then fs.exc, fs.code = fs.exc + 1, code end
  end)
end
local function next_job()
  fcall_end('end')
  job = job + 1
  if job > #jobs then return quit(0) end
  PCSX.loadSaveState(base.ss)
  count, pokes, loads, poked, reloaded, killed = base.count, base.pokes, copy(base.loads), nil, true, nil
  ovl18_at, ovl38_at, slot, s6, forced = nil, nil, nil, nil, nil
  fs, fjob, pjob, kat, kidx, pslots = nil, false, false, nil, nil, nil
  pad.clearOverride(BTN.START) pad.clearOverride(BTN.CROSS)
  if hold then pad.clearOverride(BTN[hold]) end
end

if #jobs > 0 then
  bp_poke = PCSX.addBreakpoint(POKE, 'Exec', 4, 'ovltrace poke', function()
    pokes = pokes + 1
    local j = jobs[job]
    if poked and killed == true then
      killed = 'done'
      ram()[bit.band(ST, 0x1FFFFF)], ram()[bit.band(ST + 1, 0x1FFFFF)] = j.st, j.v
      print(string.format('redux: poke2 run=%s frame=%d', run, count))
    end
    if poked or pokes ~= poke_hit then return end
    if not base then base = snap end
    run = 's' .. j.spec
    ram()[bit.band(ST, 0x1FFFFF)], ram()[bit.band(ST + 1, 0x1FFFFF)] = j.st, j.sub
    if j.b and j.d == 0 then ram()[bit.band(ST + 0x11, 0x1FFFFF)] = j.b end
    poked, fjob, pjob = count, j.fk ~= nil, j.pf ~= nil
    kat, kidx = nil, nil  -- first job: drop the boot's 800FA000 load (else the `+s/m` slot retires at once)
    print(string.format('redux: poke run=%s frame=%d', run, count))
  end)
  bp_force = PCSX.addBreakpoint(0x800203F0, 'Exec', 4, 'ovltrace force', function()
    local j = jobs[job]
    if not (poked and j.f) or forced then return end
    forced = true
    ram()[bit.band(ST + 0x11, 0x1FFFFF)] = j.f
    print(string.format('redux: force run=%s frame=%d 1C1D=%d 1598=%d stage/sub=%d/%d', run, count, j.f,
      u8(0x800D1598), u8(ST), u8(ST + 1)))
  end)
end

pause = PCSX.Events.createEventListener('ExecutionFlow::Pause', function()
  print(string.format('redux: pause run=%s frame=%d pc=%08X', run, count, PCSX.getRegisters().pc))
  -- a reload+resume from inside this handler pauses once more (seen at pc BFC05F5C) and only a second reload+resume
  -- runs on; that second pause is not the new job's fault, so it reloads the same job
  fcall_end('pause')
  if reloaded then job = job - 1 end
  if base and job < #jobs then next_job() PCSX.resumeEmulator() else quit(0) end
end)

local function tick()
  count, reloaded = count + 1, nil
  if #jobs == 0 then return end
  local k = count % 60
  if poked and hold then pad.setOverride(BTN[hold]) end
  if k == 0 then pad.setOverride(((count / 60) % 2 == 0 and not (poked and hold)) and BTN.START or BTN.CROSS)
  elseif k == 4 then pad.clearOverride(BTN.START) pad.clearOverride(BTN.CROSS) end
  if not base and pokes == poke_hit - 1 and count % 30 == 0 then
    snap = { ss = PCSX.createSaveState(), count = count, pokes = pokes, loads = copy(loads) }
  end
  local j = jobs[job]
  if poked and j.b and j.d > 0 and count - poked == j.d then
    ram()[bit.band(ST + 0x11, 0x1FFFFF)] = j.b
    print(string.format('redux: poke1d run=%s frame=%d', run, count))
  end
  if poked and j.v and not killed and count - poked == j.k then
    killed = true
    ram()[bit.band(0x8009A0FD, 0x1FFFFF)] = 0
    print(string.format('redux: kill run=%s frame=%d', run, count))
  end
  if poked and j.mv and count - poked == j.mk then
    print(string.format('redux: remode run=%s frame=%d mode=%d', run, count, u8(MODE)))
    ram()[bit.band(ST + 1, 0x1FFFFF)], ram()[bit.band(MODE, 0x1FFFFF)] = j.mv, 8
  end
  if poked and j.sp and ovl18_at and slot == nil and count - ovl18_at >= j.sp then
    slot = false
    for i = 0, NSLOT - 1 do
      if u8(POOL + i * SLOT) == 0 then slot = POOL + i * SLOT break end
    end
    if slot then
      local p = ram() + bit.band(slot, 0x1FFFFF)
      ffi.fill(p, SLOT, 0)
      p[0], p[1], p[2], p[4] = 1, 0x73, 0, 3
      ram()[bit.band(0x800D1C31, 0x1FFFFF)] = 0
    end
    print(string.format('redux: spawn run=%s frame=%d slot=%s', run, count, slot and string.format('%08X', slot) or 'none'))
  end
  if slot and not s6 and ovl38_at and count - ovl38_at >= j.sm then
    s6 = true
    local p = ram() + bit.band(slot, 0x1FFFFF)
    p[0x98], p[4] = 0, 6
    ffi.cast('uint32_t*', p + 0x14)[0] = slot + 0x98
    print(string.format('redux: state6 run=%s frame=%d slot=%08X', run, count, slot))
  end
  if fjob and slot and kat and kidx ~= 38 then
    ram()[bit.band(slot, 0x1FFFFF)], slot = 0, false
    local n = 1
    for jj, P in pairs(POOLS) do
      local tab = scr32(SCR + 4 * jj)
      for i = 0, P[3] - 1 do
        local o = P[1] + i * P[2]
        if u8(o) ~= 0 and u32(tab + 4 * u8(o + 1)) >= B800 then ram()[bit.band(o, 0x1FFFFF)], n = 0, n + 1 end
      end
    end
    print(string.format('redux: retire run=%s frame=%d k=%d n=%d', run, count, kidx, n))
  end
  if poked and j.pf and count - poked >= j.pf and (not pslots or j.pr) then
    local first, n = not pslots, 0
    pslots = pslots or {}
    for it in j.pit:gmatch('[^;]+') do
      local a, v = it:match('^(%x+)=(%x+)$')
      local pb, ps, pn, po, pv = it:match('^(%x+)%.(%x+)%.(%x+)%+(%x+)=(%x+)$')
      if pb then
        pb = tonumber(pb, 16)
        if pslots[pb] == nil then
          pslots[pb] = false
          for i = 0, tonumber(pn, 16) - 1 do
            local o = pb + i * tonumber(ps, 16)
            if u8(o) == 0 then pslots[pb] = o break end
          end
        end
        if pslots[pb] then a, v = pslots[pb] + tonumber(po, 16), pv else a = nil end
      elseif a then a = tonumber(a, 16) end
      if a then ram()[bit.band(a, 0x1FFFFF)], n = tonumber(v, 16), n + 1 end
    end
    if first then
      local sl = {}
      for pb, o in pairs(pslots) do sl[#sl + 1] = string.format('%08X:%s', pb, o and string.format('%08X', o) or 'none') end
      print(string.format('redux: fpoke run=%s frame=%d n=%d slot=%s mode=%d stage/sub=%d/%d', run, count, n,
        #sl > 0 and table.concat(sl, '/') or '-', u8(MODE), u8(ST), u8(ST + 1)))
    end
  end
  if fjob and not fs and kat and kidx == j.fk and count - kat >= j.fd then fspawn(j) end
  if fs and not fs.done and j.fF and count - fs.at >= j.fF then fcall_end('frames') end
  if poked and count - poked >= frames then next_job()
  elseif not poked and not base and count >= maxboot then quit(3) end
end

-- recycle (C0107, as replay.lua): fresh listener every RECYCLE dispatches; one body per vsync via PCSX.getCPUCycles().
-- Counted by `ticks`, not `count`: a savestate reload rewinds `count`, so `count` alone never reaches RECYCLE in poke mode.
local RECYCLE, last_cyc, retired, ticks = 16384, nil, nil, 0
local function listen()
  local self
  self = PCSX.Events.createEventListener('GPU::Vsync', function()
    if self ~= ot_vsync then return end
    if retired then retired:remove(); retired = nil end
    local c = PCSX.getCPUCycles()
    if c == last_cyc then return end
    last_cyc = c
    tick()
    ticks = ticks + 1
    if ticks % RECYCLE == 0 then retired = ot_vsync; ot_vsync = listen() end
  end)
  return self
end
ot_vsync = listen()

if os.getenv('REDUX_PAD') then dofile(dir .. '/replay.lua') end
