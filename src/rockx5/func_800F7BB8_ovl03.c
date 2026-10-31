#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;

void func_800F7BB8_ovl03(u8* obj) {
    s32 v;

    v = *(s32*)(obj + 0x20);
    if (v < 0) {
        if (*(s16*)(obj + 0xA) <= D_800FA240_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA240_ovl03;
            *(s32*)(obj + 0x20) = 0;
            obj[0x8E] = 0;
        }
    } else if (v > 0) {
        if (*(s16*)(obj + 0xA) >= D_800FA242_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA242_ovl03;
            *(s32*)(obj + 0x20) = 0;
            obj[0x8E] = 1;
        }
    }
    if (*(s16*)(obj + 0xE) <= D_800FA244_ovl03) {
        *(s16*)(obj + 0xE) = D_800FA244_ovl03;
        *(s32*)(obj + 0x24) = 0;
    }
    if (*(s32*)(obj + 0x20) == 0 && *(s32*)(obj + 0x24) == 0) {
        obj[0x8F] = 0;
        *(s16*)(obj + 0x7C) = 0;
        obj[0x6]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
