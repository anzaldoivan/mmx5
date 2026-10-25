#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8003D010(s8 dmg);
extern u8 D_8009A0A0[];

void func_800F2A9C_ovl04(u8* obj) {
    u8* src = D_8009A0A0;

    *(u16*)(obj + 0xA) = *(u16*)(src + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(src + 0xE);
    if (--*(s16*)(obj + 0x7C) == -1) {
        func_800171E8(obj, 4);
        func_8003D010(2);
        *(s16*)(obj + 0x7C) = 0x78;
    }
}
