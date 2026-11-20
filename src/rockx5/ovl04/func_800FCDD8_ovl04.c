#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern void func_8002A600(s32, s32, s32);
extern u16 D_8009A22C;
extern u8 D_800D1C00[];

void func_800FCDD8_ovl04(u8* a0) {
    u8* p;
    u32 r;

    a0[0x8D]++;
    *(s32*)(a0 + 0xC) += 0xFFFF0000;
    if ((u8)(a0[0x8D] % 40) == 0) {
        play_sound(2, 0x13, a0);
    }
    if (*(s16*)(a0 + 0xE) >= 0x46C && D_8009A22C == 0) {
        func_8002A600(0x10, 3, 2);
    }
    if (*(s16*)(a0 + 0xE) < 0x471) {
        a0[5]++;
        D_800D1C00[0x27] = 0;
        D_800D1C00[0x2A] = 0;
        D_800D1C00[0x28] = 0;
        D_800D1C00[0x29] = 0;
        D_800D1C00[0x2B] = 0;
        D_800D1C00[0x26] = 1;
        a0[0x8D] = 0x3C;
        r = random_byte();
        *(s16*)(a0 + 0x8A) = 0;
        a0[0x91] = 0;
        a0[0x90] = 0;
        *(s16*)(a0 + 0x88) = (u8)(r % 50) + 40;
    }
    if (!(D_8009A420_as_s32 & 7) && (random_byte() & 0x10)) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x18;
            p[2] = 0;
            *(u8**)(p + 0x50) = a0;
        }
    }
}
