#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800D1D10;
extern void silence_sound(s32, s32);
extern void clear_flash_palette(u8* obj);
extern void func_8003C5D8(u8* obj);

void func_8003F35C(void) {
    u8* p = g_Player;

    if ((D_800D1D10 & 1) && *(s8*)(p + 0x93) == 0) {
        return;
    }
    if (!(*(u16*)(p + 0x7C) & 0x10)) {
        p[0x9B] = 0;
        p[0x9D] = 0;
    }
    if (!(*(u16*)(p + 0x7C) & 0x20)) {
        p[0x9C] = 0;
        p[0x9E] = 0;
    }
    if (!(*(s32*)(p + 0x9C) & 0xFFFF00)) {
        silence_sound(1, 7);
        clear_flash_palette(p);
        p[0x9B] = 0;
        p[0x9C] = 0;
        p[0x9D] = 0;
        p[0x9E] = 0;
        func_8003C5D8(p);
    }
}
