#include "types.h"

extern u8 D_8009A0B5;
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8003D29C(s32, s32);

void func_800F78F4_ovl09(u8* obj) {
    u8* child = *(u8**)(obj + 0x80);
    s8 v = *(s8*)(child + 0x45);

    if (v == 1) {
        func_800171E8(child, 4);
        *(*(u8**)(obj + 0x7C) + 0x54) = v;
        *(s16*)(obj + 0x84) = 0;
        func_8003D29C(0x16, D_8009A0B5);
        obj[6]++;
    }
}
