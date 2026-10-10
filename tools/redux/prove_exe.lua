-- prove_exe.lua -- live windows for the SLUS_013.34 load-address proof (T5; driven by tools/loadmap/prove.py).
-- After REDUX_FRAMES vsyncs (default 300) print sha1 of REDUX_LEN (256) RAM bytes at A-4, A, A+4 for each A in
-- REDUX_WINDOWS (comma list of hex addrs) and the u32 at 80010000; quit 0. Hashes only, never bytes (G12).
local ffi, bit = require('ffi'), require('bit')
local sha1 = dofile(debug.getinfo(1, 'S').source:sub(2):match('^(.*)/') .. '/sha1.lua')

local frames = tonumber(os.getenv('REDUX_FRAMES') or '300')
local LEN = tonumber(os.getenv('REDUX_LEN') or '256')
local windows = {}
for a in (os.getenv('REDUX_WINDOWS') or ''):gmatch('[^,]+') do windows[#windows + 1] = tonumber(a) end

local count = 0
listener = PCSX.Events.createEventListener('GPU::Vsync', function()
  count = count + 1
  if count < frames then return end
  local ram = ffi.cast('uint8_t*', PCSX.getMemPtr())
  for _, a in ipairs(windows) do
    for _, d in ipairs({ -4, 0, 4 }) do
      local p = a + d
      print(string.format('redux: win frames=%d addr=%08X delta=%d len=%d sha1=%s', count, a, d, LEN,
        sha1(ffi.string(ram + bit.band(p, 0x1FFFFF), LEN))))
    end
  end
  print(string.format('redux: base *80010000=%08X', ffi.cast('uint32_t*', ram + 0x10000)[0]))
  PCSX.quit(0)
end)
