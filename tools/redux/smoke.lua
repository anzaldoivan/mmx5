-- smoke.lua -- PCSX-Redux Lua bridge smoke test (T3).
-- After REDUX_FRAMES vsyncs (default 300), sha1 256 bytes of RAM at REDUX_ADDR (default 0x80010000)
-- and compare with REDUX_EXPECT_SHA1 (run.sh computes it from the SLUS_013.34 file slice).
-- Prints hashes only, never bytes (G12). Exit: 0 match, 1 mismatch, 2 missing expectation.
local ffi, bit = require('ffi'), require('bit')
local band, bor, bxor, bnot, rol, tobit = bit.band, bit.bor, bit.bxor, bit.bnot, bit.rol, bit.tobit

local addr = tonumber(os.getenv('REDUX_ADDR') or '0x80010000')
local frames = tonumber(os.getenv('REDUX_FRAMES') or '300')
local expect = os.getenv('REDUX_EXPECT_SHA1')
local LEN = 256

-- sha1 of a Lua string (LuaJIT bit ops)
local function sha1(s)
  local n = #s
  s = s .. '\128' .. string.rep('\0', (55 - n) % 64)
  local bits = n * 8
  for i = 7, 0, -1 do s = s .. string.char(math.floor(bits / 2 ^ (8 * i)) % 256) end
  local h0, h1, h2, h3, h4 = tobit(0x67452301), tobit(0xEFCDAB89), tobit(0x98BADCFE), tobit(0x10325476), tobit(0xC3D2E1F0)
  local w = {}
  for c = 1, #s, 64 do
    for i = 0, 15 do
      local a, b2, c2, d = s:byte(c + 4 * i, c + 4 * i + 3)
      w[i] = bor(bit.lshift(a, 24), bit.lshift(b2, 16), bit.lshift(c2, 8), d)
    end
    for i = 16, 79 do w[i] = rol(bxor(w[i - 3], w[i - 8], w[i - 14], w[i - 16]), 1) end
    local a, b, cc, d, e = h0, h1, h2, h3, h4
    for i = 0, 79 do
      local f, k
      if i < 20 then f, k = bor(band(b, cc), band(bnot(b), d)), 0x5A827999
      elseif i < 40 then f, k = bxor(b, cc, d), 0x6ED9EBA1
      elseif i < 60 then f, k = bor(band(b, cc), band(b, d), band(cc, d)), 0x8F1BBCDC
      else f, k = bxor(b, cc, d), 0xCA62C1D6 end
      local t = tobit(rol(a, 5) + f + e + k + w[i])
      e, d, cc, b, a = d, cc, rol(b, 30), a, t
    end
    h0, h1, h2, h3, h4 = tobit(h0 + a), tobit(h1 + b), tobit(h2 + cc), tobit(h3 + d), tobit(h4 + e)
  end
  return bit.tohex(h0) .. bit.tohex(h1) .. bit.tohex(h2) .. bit.tohex(h3) .. bit.tohex(h4)
end
assert(sha1('abc') == 'a9993e364706816aba3e25717850c26c9cd0d89d', 'sha1 self-check')

local count = 0
listener = PCSX.Events.createEventListener('GPU::Vsync', function()
  count = count + 1
  if count < frames then return end
  local ram = ffi.cast('uint8_t*', PCSX.getMemPtr())
  local got = sha1(ffi.string(ram + band(addr, 0x1FFFFF), LEN))
  print(string.format('redux: frames=%d addr=0x%08X len=%d ram_sha1=%s expect_sha1=%s', count, addr, LEN, got, tostring(expect)))
  if not expect then print('redux: REDUX_EXPECT_SHA1 not set'); PCSX.quit(2)
  elseif got ~= expect then print('redux: MISMATCH'); PCSX.quit(1)
  else print('redux: lua ok'); PCSX.quit(0) end
end)
