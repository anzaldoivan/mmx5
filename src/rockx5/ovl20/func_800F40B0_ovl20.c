#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u32* D_80098118;
extern u8 D_800D1C00[];

void func_800F40B0_ovl20(u8* p) {
    if ((s8)D_800D1C00[0x32] != 0) {
        p[0] &= 0xEF;
    } else {
        p[0] |= 0x10;
    }
    animate_object(p);
    if ((s8)D_800D1C00[0x2A] != *(s8*)(p + 0x54)) {
        if ((s8)D_800D1C00[0x2A] == 5) {
            u32* t = D_80098118;
            *(u16*)(p + 0x42) = 0x7808;
            *(u16*)(p + 0x40) = t[2] >> 7;
            *(s32*)(p + 0x3C) = (s32)D_1F800020.s32s + D_1F800020.s32s[2];
        } else {
            u32* t = D_80098118;
            *(u16*)(p + 0x42) = 0x7804;
            *(u16*)(p + 0x40) = t[1] >> 7;
            *(s32*)(p + 0x3C) = (s32)D_1F800020.s32s + D_1F800020.s32s[1];
        }
        if ((s8)D_800D1C00[0x2A] == 5) {
            if (D_800D1C00[0x4A] & 0x10) {
                set_animation(p, 7);
            } else {
                goto other; // !FAKE: goto kept for the matching branch layout
            }
        } else {
        other:
            set_animation(p, (s8)D_800D1C00[0x2A]);
        }
    }
    func_8002D89C(p);
}
