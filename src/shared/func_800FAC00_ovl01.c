#include "types.h"

extern u8 D_800D1C00[];
extern s16 D_8009A1F8[];

void func_800FAC00_ovl01(u8* obj) {
    if ((signed char)D_800D1C00[0xF] == 0) {
        if ((signed char)D_800D1C00[0xC] != 0xC) {
            s16* p = D_8009A1F8;
            p[0x12] = p[0x13] = 0x25B0;
            p[0x14] = p[0x15] = 0xF0;
        } else {
            s16* p = D_8009A1F8;
            p[0x12] = p[0x13] = 0x2B0;
        }
        if (--*(s16*)(obj + 0x7C) == 0) {
            obj[6] = 2;
        }
    }
}
