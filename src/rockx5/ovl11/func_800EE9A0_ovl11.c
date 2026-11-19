#include "types.h"

extern s32 rsin(s32);
extern u8 D_8009A197;
extern u8 D_8009A1F8[];
extern s8 D_800D1C00[];
extern void* D_800F8F94_ovl11[];

void func_800EE9A0_ovl11(u8* obj) {
    s32 v;
    u8* p;

    if (D_8009A197 != 0) {
        return;
    }
    ((void (*)(u8*))D_800F8F94_ovl11[(s8)obj[4]])(obj);
    if (D_800D1C00[0x27] != 0) {
        *(s32*)(obj + 0x18) = 0x0C000000;
        obj[0x1C] = 1;
        D_800D1C00[0x27] = 0;
    }
    if (((s8*)obj)[0x1C] != 0) {
        v = rsin(*(s16*)(obj + 0x1A)) + 0x1000;
        v <<= 5;
        v = v / 0x2000;
        v += 0xF0;
        if (v > 0x10F) {
            v = 0x10F;
        }
        if (v < 0xF1) {
            v = 0xF1;
        }
        p = D_8009A1F8;
        *(s16*)(p + 0x2A) = v;
        *(s16*)(p + 0x28) = v;
        *(s32*)(obj + 0x18) += 0x110000;
    }
    if (D_800D1C00[0x28] != 0) {
        *(s32*)(obj + 0x14) += 0x1000;
        if (*(s32*)(obj + 0x14) > 0x30000) {
            *(s32*)(obj + 0x14) = 0x30000;
        }
    }
}
