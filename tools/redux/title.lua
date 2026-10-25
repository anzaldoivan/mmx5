-- title.lua -- title-screen probe (T4): boot to the "PRESS START BUTTON" title, pin RAM state + displayed VRAM.
-- Needs `-interpreter`: under the dynarec (Redux 298) the game stalls before the intro FMV (screen frozen).
-- After FRAMES vsyncs (no input): sha1 of the stage/sub bytes *800D1C0C/0D (title = 14/0) and sha1 of the screenshot
-- pixels (PCSX.GPU.takeScreenShot: the display area of VRAM, 320x240 15-bit; build 298's Lua has no whole-VRAM read).
-- Writes .run/redux/title.png (cwd = .run/redux, set by run.sh). Hashes only on stdout (G12).
-- Exit: 0 both hashes equal the pins (`redux: title OK`), 1 mismatch, 2 run under the dynarec.
local ffi = require('ffi')
local dir = debug.getinfo(1, 'S').source:sub(2):match('^(.*)/')
local sha1, png = dofile(dir .. '/sha1.lua'), dofile(dir .. '/png.lua')

local FRAMES = 5000  -- first round count on the title's stable 2-state loop (blinking prompt); 4975 still animates
local RAM_SHA1 = 'adf2661d275d11e81149306f5d08b9d5e84c7307'   -- sha1(*800D1C0C, 2 bytes)
local VRAM_SHA1 = 'f44fc02bcf2ac6000c199d4587227bcc7b8f6ed8'  -- sha1(screenshot pixels)

if PCSX.settings.emulator.Dynarec then print('redux: title needs -interpreter'); PCSX.quit(2) end
local count = 0
listener = PCSX.Events.createEventListener('GPU::Vsync', function()
  count = count + 1
  if count < FRAMES then return end
  local ram = ffi.cast('uint8_t*', PCSX.getMemPtr())
  local ss = PCSX.GPU.takeScreenShot()
  local px = tostring(ss.data)
  local r, v = sha1(ffi.string(ram + 0xD1C0C, 2)), sha1(px)
  if tonumber(ss.bpp) == 0 and #px == ss.width * ss.height * 2 then png(px, ss.width, ss.height, 'title.png') end
  print(string.format('redux: frames=%d stage/sub=%d/%d %dx%d bpp=%d ram_sha1=%s vram_sha1=%s', count, ram[0xD1C0C],
    ram[0xD1C0D], ss.width, ss.height, tonumber(ss.bpp), r, v))
  if r == RAM_SHA1 and v == VRAM_SHA1 then print('redux: title OK'); PCSX.quit(0)
  else print('redux: title MISMATCH'); PCSX.quit(1) end
end)
