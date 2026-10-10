-- prove_ovl3839.lua -- live destination of ROCK_X5.BIN overlays 38/39 (T2 phase 1.8.3; driven by tools/loadmap/prove.py ovl3839).
-- Needs `-interpreter -debugger`. Exec bp on Ovl_Load 80015EB4 logs every hit (frame, a0 idx, a1 dest, ra, stage byte
-- *800D1C0C, sub byte *800D1C0D, live TOC row 800E6188+8*idx). ovl38/39 are loaded by ovl18 (stage 12 sub 0), so pad 1
-- is tapped (START / CROSS alternately, every REDUX_TAP frames, held 4) through the whole run. REDUX_STAGE=<n>: exec bp at
-- 800136D4 writes stage=n, sub=0 once, on its REDUX_POKE_HIT-th hit (default 1) (`poke`); REDUX_HOLD=<button> holds it
-- after the poke and taps CROSS only. Pad API: PCSX.SIO0.slots[1].pads[1].setOverride(b) (dot call), PCSX.CONSTS.PAD.BUTTON.
-- For idx 38/39: sha1 of dest region (live TOC size) before; after = the last state before the next Ovl_Load hit or REDUX_FRAMES (prove_overlay.lua's DMA rule). Quits early once ovl39's
-- region has held 600 frames. Stage/sub changes logged (`stage`). Hashes only (G12). Exit 0; 3 if no 38/39 after.
local ffi, bit = require('ffi'), require('bit')
local sha1 = dofile(debug.getinfo(1, 'S').source:sub(2):match('^(.*)/') .. '/sha1.lua')

local frames = tonumber(os.getenv('REDUX_FRAMES') or '20000')
local tap = tonumber(os.getenv('REDUX_TAP') or '60')
local stage = tonumber(os.getenv('REDUX_STAGE') or '')
local poke_hit = tonumber(os.getenv('REDUX_POKE_HIT') or '1')  -- poke on the n-th 800136D4 hit
local hold = os.getenv('REDUX_HOLD')  -- after the poke: hold this button (e.g. RIGHT), tap CROSS only
local TOC, ST = 0x800E6188, 0x800D1C0C
local BTN = PCSX.CONSTS.PAD.BUTTON
local pad = PCSX.SIO0.slots[1].pads[1]
local count, cur, done, poked, pokes, st = 0, nil, {}, false, 0, nil

local function ram() return ffi.cast('uint8_t*', PCSX.getMemPtr()) end
local function u8(a) return ram()[bit.band(a, 0x1FFFFF)] end
local function u32(a) return ffi.cast('uint32_t*', ram() + bit.band(a, 0x1FFFFC))[0] end
local function hash(a, n) return sha1(ffi.string(ram() + bit.band(a, 0x1FFFFF), n)) end

local function finish()
  if not cur then return end
  print(string.format('redux: ovl after frame=%d held=%d idx=%d dest=%08X size=%X sha1=%s',
    cur.since, count - cur.since, cur.idx, cur.dest, cur.size, cur.last))
  done[cur.idx], cur = true, nil
end

bp_load = PCSX.addBreakpoint(0x80015EB4, 'Exec', 4, 'Ovl_Load', function()
  local r = PCSX.getRegisters().GPR.n
  local idx, dest = r.a0, r.a1
  local size = u32(TOC + 8 * idx + 4)
  print(string.format('redux: hit Ovl_Load frame=%d idx=%d dest=%08X ra=%08X stage=%d sub=%d toc_sec=%X toc_size=%X',
    count, idx, dest, r.ra, u8(ST), u8(ST + 1), u32(TOC + 8 * idx), size))
  finish()
  if idx == 38 or idx == 39 then
    local h = hash(dest, size)
    cur = { idx = idx, dest = dest, size = size, last = h, since = count }
    print(string.format('redux: ovl before frame=%d idx=%d dest=%08X size=%X sha1=%s', count, idx, dest, size, h))
  end
end)
if stage then
  bp_poke = PCSX.addBreakpoint(0x800136D4, 'Exec', 4, 'stage poke', function()
    pokes = pokes + 1
    if poked or pokes < poke_hit then return end
    poked = true
    ram()[bit.band(ST, 0x1FFFFF)], ram()[bit.band(ST + 1, 0x1FFFFF)] = stage, 0
    print(string.format('redux: poke frame=%d stage=%d sub=0', count, stage))
  end)
end

listener = PCSX.Events.createEventListener('GPU::Vsync', function()
  count = count + 1
  local k = count % tap
  if poked and hold then pad.setOverride(BTN[hold]) end
  if k == 0 then pad.setOverride(((count / tap) % 2 == 0 and not (poked and hold)) and BTN.START or BTN.CROSS)
  elseif k == 4 then pad.clearOverride(BTN.START) pad.clearOverride(BTN.CROSS) end
  local s = string.format('%d/%d', u8(ST), u8(ST + 1))
  if s ~= st then st = s print(string.format('redux: stage frame=%d stage/sub=%s', count, s)) end
  if cur then
    local h = hash(cur.dest, cur.size)
    if h ~= cur.last then
      cur.last, cur.since = h, count
      print(string.format('redux: ovl change frame=%d idx=%d sha1=%s', count, cur.idx, h))
    end
  end
  if count >= frames or (cur and cur.idx == 39 and count - cur.since >= 600) then
    finish()
    print(string.format('redux: done frames=%d ovl38=%s ovl39=%s', count, tostring(done[38] or false), tostring(done[39] or false)))
    PCSX.quit((done[38] or done[39]) and 0 or 3)
  end
end)
