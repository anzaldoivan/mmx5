#include "types.h"

extern u8* func_8002D1A4();
extern s32 func_8002DF78();
extern signed char D_800D1CA2;

void func_800FAFE0_ovl27(u8* arg0, s32 arg1) {
    u8* p;
    u8* obj;
    u8 type;
    u8 b;

    type = arg1;
    obj = *(u8**)(arg0 + 0x7C);
    if (D_800D1CA2 / 2 >= *(s8*)(obj + 0x5C)) {
        p = func_8002D1A4(obj, *(s8*)(obj + 0x5C));
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x21;
            obj = *(u8**)(arg0 + 0x7C);
            p[2] = type;
            *(u8**)(p + 0x7C) = obj;
            *(s16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
            *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
            *(s16*)(p + 0x40) = *(s16*)(arg0 + 0x40);
            b = arg0[0x14];
            *(s16*)(p + 0x8) = 0;
            *(s16*)(p + 0xC) = 0;
            p[0x14] = b;
            if (type == 2) {
                *(s16*)(p + 0xA) = *(s16*)(arg0 + 0xA) + 0x30;
            } else {
                *(s16*)(p + 0xA) = *(s16*)(arg0 + 0xA) - 0x30;
            }
            if (func_8002DF78(b) & 1) {
                *(s16*)(p + 0xE) = *(s16*)(arg0 + 0xE) - 0x28;
            } else {
                *(s16*)(p + 0xE) = *(s16*)(arg0 + 0xE) + 0x28;
            }
        }
    }
}
