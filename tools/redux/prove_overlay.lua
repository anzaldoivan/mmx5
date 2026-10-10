-- prove_overlay.lua -- live before/after of the first ROCK_X5.BIN overlay load (T5; driven by tools/loadmap/prove.py).
-- Needs `-interpreter -debugger` (exec breakpoints do not fire otherwise). Exec breakpoints on Ovl_Load 80015EB4
-- (logs a0 index, a1 dest, ra, *(80010000), live TOC row 800E6188+8*idx) and Cd_Unk_80014064 (was Ovl_Load2) / Ovl_Load3 80014290
-- (logged only). First Ovl_Load hit: sha1 of dest region (live TOC size) before. Ovl_Load returns before the CD DMA
-- lands (sectors arrive frames apart, gaps > 10 vsyncs seen), so after Ovl_Load returns (exec bp on its ra) every
-- vsync's hash change is logged (`ovl change`) and after = the last state reached before the next Ovl_Load hit or
-- REDUX_FRAMES (default 5000), with the frame it was reached and how long it held. Hashes only (G12). Exit 0; 3 if no
-- hit/after.
local ffi, bit = require('ffi'), require('bit')
local sha1 = dofile(debug.getinfo(1, 'S').source:sub(2):match('^(.*)/') .. '/sha1.lua')

local frames = tonumber(os.getenv('REDUX_FRAMES') or '5000')
local TOC = 0x800E6188
local count = 0
local first, returned, after, last, since = nil, false, nil, nil, 0

local function ram() return ffi.cast('uint8_t*', PCSX.getMemPtr()) end
local function u32(a) return ffi.cast('uint32_t*', ram() + bit.band(a, 0x1FFFFC))[0] end
local function hash(a, n) return sha1(ffi.string(ram() + bit.band(a, 0x1FFFFF), n)) end

local function finish()
  if after or not last then return end
  after = last
  print(string.format('redux: ovl after frame=%d held=%d idx=%d dest=%08X size=%X sha1=%s',
    since, count - since, first.idx, first.dest, first.size, after))
end

bp_load = PCSX.addBreakpoint(0x80015EB4, 'Exec', 4, 'Ovl_Load', function()
  local r = PCSX.getRegisters().GPR.n
  local idx, dest, ra = r.a0, r.a1, r.ra
  local sec, size = u32(TOC + 8 * idx), u32(TOC + 8 * idx + 4)
  print(string.format('redux: hit Ovl_Load frame=%d idx=%d dest=%08X ra=%08X base=%08X toc_sec=%X toc_size=%X',
    count, idx, dest, ra, u32(0x80010000), sec, size))
  if first then finish() return end
  first = { idx = idx, dest = dest, size = size, ra = ra }
  print(string.format('redux: ovl before frame=%d idx=%d dest=%08X size=%X sha1=%s', count, idx, dest, size, hash(dest, size)))
  bp_ret = PCSX.addBreakpoint(ra, 'Exec', 4, 'Ovl_Load ret', function()
    if returned then return end
    returned = true
    print(string.format('redux: ovl return frame=%d sha1=%s', count, hash(first.dest, first.size)))
  end)
end)
bp_log = {}  -- keep the breakpoint handles referenced: a collected handle removes its breakpoint
for name, a in pairs({ Cd_Unk_80014064 = 0x80014064, Ovl_Load3 = 0x80014290 }) do
  bp_log[name] = PCSX.addBreakpoint(a, 'Exec', 4, name, function()
    local r = PCSX.getRegisters().GPR.n
    print(string.format('redux: hit %s frame=%d a0=%08X a1=%08X ra=%08X', name, count, r.a0, r.a1, r.ra))
  end)
end

listener = PCSX.Events.createEventListener('GPU::Vsync', function()
  count = count + 1
  if returned and not after then
    local h = hash(first.dest, first.size)
    if h ~= last then
      last, since = h, count
      print(string.format('redux: ovl change frame=%d sha1=%s', count, h))
    end
  end
  if count >= frames then
    finish()
    print(string.format('redux: done frames=%d first=%s after=%s', count, tostring(first ~= nil), tostring(after ~= nil)))
    PCSX.quit(after and 0 or 3)
  end
end)
