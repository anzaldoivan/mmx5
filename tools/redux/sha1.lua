-- sha1.lua -- LuaJIT sha1 of a Lua string (copied from smoke.lua, T3); `local sha1 = dofile(<dir>/sha1.lua)`.
local bit = require('bit')
local band, bor, bxor, bnot, rol, tobit = bit.band, bit.bor, bit.bxor, bit.bnot, bit.rol, bit.tobit

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
return sha1
