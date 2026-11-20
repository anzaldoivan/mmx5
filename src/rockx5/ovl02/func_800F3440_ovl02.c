#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern s32 func_8002B5B4(s32);
extern void set_animation_frame(u8* a0, s32 a1, s32 a2);
extern int func_8002D7A0();
extern u32* D_80098118;
extern u8 D_800F490C_ovl02;

void func_800F3440_ovl02(u8* p) {
    s32 r0;
    s32 r1;

    if (((s8*)p)[4] == 0) {
        *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(0x94)] >> 7;
        *(s32*)(p + 0x3C) =
            (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x94)];
        r0 = func_8002B5B4(0x94);
        r1 = func_8002B5B4(0x94);
        *(u16*)(p + 0x42) =
            ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
        *(u8**)(p + 0x30) = &D_800F490C_ovl02;
        p[0x14] = 0;
        p[0x15] = 0;
        ((s32(*)())set_animation)(p, 0);
        p[0x16] = 0;
        p[4]++;
    } else {
        set_animation_frame(p, ((s8*)p)[2], (D_8009A420_as_s32 % 102) / 17);
        if (is_off_screen(p, 0x20, 0x20) == 0) {
            func_8002D9EC(p, 0x20, 0x20);
        } else {
            func_8002D7A0(p);
        }
    }
}
