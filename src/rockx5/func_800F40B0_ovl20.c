#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D89C(u8* obj);
extern u32* D_80098118;
extern u8 D_800D1C00[];

void func_800F40B0_ovl20(u8* p) {
    if ((s8)D_800D1C00[0x32] != 0) {
        p[0] &= 0xEF;
    } else {
        p[0] |= 0x10;
    }
    func_80017248(p);
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
                func_800171E8(p, 7);
            } else {
                goto other; // !FAKE: goto kept for the matching branch layout
            }
        } else {
        other:
            func_800171E8(p, (s8)D_800D1C00[0x2A]);
        }
    }
    func_8002D89C(p);
}
