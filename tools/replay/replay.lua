-- replay.lua -- deterministic pad-script replay (T1 phase 2.2); driven by tools/replay/replay.py (format: README.md).
-- Needs `-interpreter`: under the dynarec (Redux 298) the game stalls before the intro FMV (C0104).
-- Env REDUX_PAD = .pad file (absolute; cwd is .run/redux), REDUX_OUT = directory for <name>.png (default cwd),
-- REDUX_PLANT = <hexaddr>:<hexword>@<frame> (optional RAM write, `redux: plant …`).
-- Frame n = the n-th GPU::Vsync. Each frame's .pad lines run in file order: press/release = pad 1 override,
-- cp = `redux: cp <name> frame=<n> stage/sub=<s>/<u> vram_sha1=<h>` + PNG, end = `redux: end frame=<n>` + quit 0.
-- Hash = sha1 of the screenshot pixels (as title.lua); stage/sub = *800D1C0C/0D. Hashes only on stdout (G12).
-- Exit: 0 at `end`, 2 dynarec or bad .pad.
local ffi, bit = require('ffi'), require('bit')
local dir = debug.getinfo(1, 'S').source:sub(2):match('^(.*)/')
local sha1, png = dofile(dir .. '/../redux/sha1.lua'), dofile(dir .. '/../redux/png.lua')

if PCSX.settings.emulator.Dynarec then print('redux: replay needs -interpreter'); PCSX.quit(2) end
local BTN = PCSX.CONSTS.PAD.BUTTON
local pad = PCSX.SIO0.slots[1].pads[1]
local out = os.getenv('REDUX_OUT') or '.'

local ev, path = {}, os.getenv('REDUX_PAD')
local ok = path and io.open(path) ~= nil
for line in (ok and io.lines(path) or function() end) do
  local f, op, arg = line:gsub('#.*', ''):match('^%s*(%d+)%s+(%a+)%s*(%S*)%s*$')
  f = tonumber(f)
  if not f then ok = ok and not line:gsub('#.*', ''):match('%S')
  elseif (op == 'press' or op == 'release') and BTN[arg] or op == 'cp' and arg ~= '' or op == 'end' then
    ev[f] = ev[f] or {}
    table.insert(ev[f], { op, arg })
  else ok = false end
  if not ok then print('redux: bad pad line: ' .. line); break end
end
if not ok then print('redux: bad pad ' .. tostring(path)); PCSX.quit(2) end

-- REDUX_PLANT=<hexaddr>:<hexword>@<frame>: at that vsync write the 32-bit word (LE) at addr (negative control, check).
local plant = os.getenv('REDUX_PLANT')
local p_addr, p_word, p_frame
if plant and plant ~= '' then
  local a, w, f = plant:match('^(%x+):(%x+)@(%d+)$')
  if not a then print('redux: bad REDUX_PLANT ' .. plant); PCSX.quit(2) end
  p_addr, p_word, p_frame = tonumber(a, 16), tonumber(w, 16), tonumber(f)
end

-- Leak fix (R2.2-001): each dispatch leaves 2 tables on the listener's own coroutine thread, so one listener
-- overflows the Lua stack at vsync 32736. Every RECYCLE vsyncs a fresh listener (fresh thread) takes over and the old
-- one is removed from the new one's callback (never inside its own). A listener created in a callback fires in the
-- same dispatch (probe), so the body is guarded by PCSX.getCPUCycles(): one body per vsync, never skipped or doubled.
local RECYCLE = 16384
local count, last_cyc, retired = 0, nil, nil
local function body()
  count = count + 1
  if count == p_frame then
    ffi.cast('uint32_t*', ffi.cast('uint8_t*', PCSX.getMemPtr()) + bit.band(p_addr, 0x1FFFFC))[0] = p_word
    PCSX.invalidateCache()
    print(string.format('redux: plant addr=%08X word=%08X frame=%d', p_addr, p_word, count))
  end
  for _, e in ipairs(ev[count] or {}) do
    local op, arg = e[1], e[2]
    if op == 'press' then pad.setOverride(BTN[arg])
    elseif op == 'release' then pad.clearOverride(BTN[arg])
    elseif op == 'cp' then
      local ram = ffi.cast('uint8_t*', PCSX.getMemPtr())
      local ss = PCSX.GPU.takeScreenShot()
      local px = tostring(ss.data)
      if tonumber(ss.bpp) == 0 and #px == ss.width * ss.height * 2 then png(px, ss.width, ss.height, out .. '/' .. arg .. '.png') end
      print(string.format('redux: cp %s frame=%d stage/sub=%d/%d vram_sha1=%s', arg, count, ram[0xD1C0C], ram[0xD1C0D], sha1(px)))
    else print(string.format('redux: end frame=%d', count)); PCSX.quit(0) end
  end
end
local function listen()
  local self
  self = PCSX.Events.createEventListener('GPU::Vsync', function()
    if self ~= listener then return end  -- retired, awaiting removal
    if retired then retired:remove(); retired = nil end
    local c = PCSX.getCPUCycles()
    if c == last_cyc then return end  -- this vsync's body already ran (on the retired listener)
    last_cyc = c
    body()
    if count % RECYCLE == 0 then retired = listener; listener = listen() end
  end)
  return self
end
listener = listen()
