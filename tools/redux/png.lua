-- png.lua -- 15-bit BGR555 screenshot pixels -> RGB8 PNG file (moved out of title.lua, T1 phase 2.2);
-- `local png = dofile(<dir>/png.lua)`; `png(px, w, h, path)` with px = tostring(PCSX.GPU.takeScreenShot().data).
local ffi, bit = require('ffi'), require('bit')

local function u32be(n) return string.char(bit.band(bit.rshift(n, 24), 255), bit.band(bit.rshift(n, 16), 255),
  bit.band(bit.rshift(n, 8), 255), bit.band(n, 255)) end
local crct = {}
for i = 0, 255 do
  local c = i
  for _ = 1, 8 do c = bit.band(c, 1) == 1 and bit.bxor(0xEDB88320, bit.rshift(c, 1)) or bit.rshift(c, 1) end
  crct[i] = c
end
local function crc32(s)
  local c = bit.bnot(0)
  for i = 1, #s do c = bit.bxor(crct[bit.band(bit.bxor(c, s:byte(i)), 255)], bit.rshift(c, 8)) end
  return bit.bnot(c)
end
local function chunk(t, d) return u32be(#d) .. t .. d .. u32be(crc32(t .. d)) end

-- 15-bit BGR555 little-endian -> RGB8 PNG, zlib stored blocks
local function png(px, w, h, path)
  local src, rows = ffi.cast('const uint8_t*', px), {}
  for y = 0, h - 1 do
    local row = { '\0' }
    for x = 0, w - 1 do
      local p = src[2 * (y * w + x)] + 256 * src[2 * (y * w + x) + 1]
      row[#row + 1] = string.char(bit.lshift(bit.band(p, 31), 3), bit.lshift(bit.band(bit.rshift(p, 5), 31), 3),
        bit.lshift(bit.band(bit.rshift(p, 10), 31), 3))
    end
    rows[#rows + 1] = table.concat(row)
  end
  local raw, z, a, b = table.concat(rows), { '\120\1' }, 1, 0
  for i = 1, #raw do a = (a + raw:byte(i)) % 65521; b = (b + a) % 65521 end
  for o = 1, #raw, 65535 do
    local blk = raw:sub(o, o + 65534)
    z[#z + 1] = string.char(o + 65535 > #raw and 1 or 0, #blk % 256, math.floor(#blk / 256),
      255 - #blk % 256, 255 - math.floor(#blk / 256)) .. blk
  end
  z[#z + 1] = u32be(b * 65536 + a)
  local f = assert(io.open(path, 'wb'))
  f:write('\137PNG\r\n\26\n', chunk('IHDR', u32be(w) .. u32be(h) .. '\8\2\0\0\0'), chunk('IDAT', table.concat(z)), chunk('IEND', ''))
  f:close()
end

return png
