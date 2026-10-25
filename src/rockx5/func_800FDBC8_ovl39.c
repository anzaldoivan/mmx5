#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FEC18_ovl39[];
extern u8 D_800FEC14_ovl39[];

void func_800FDBC8_ovl39(u8* obj) {
    s32 t;

    if (*(s8*)(obj + 0x2) == 0) {
        *(u8*)(obj + 0x15) = 0;
        *(s16*)(obj + 0xA) = 0x12E0;
        *(s32*)(obj + 0x20) = -0x18000;
    } else {
        *(u8*)(obj + 0x15) = 0x40;
        *(s16*)(obj + 0xA) = 0x1140;
        *(s32*)(obj + 0x20) = 0x18000;
    }
    t = 0x820;
    *(s16*)(obj + 0xE) = t;
    t = (s32)D_800FEC18_ovl39;
    *(s32*)(obj + 0x54) = t;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x50) = 0;
    *(u8**)(obj + 0x68) = D_800FEC14_ovl39;
    *(u8*)(obj + 0x8A) = 0;
    func_800171E8(obj, 0);
    *(u8*)(*(u8**)(obj + 0x7C) + 0x89) = 0;
    *(u8*)(obj + 0x6) += 1;
}
