#include "types.h"

extern u8 D_8009A197;
extern u8 D_8009A1F8[];
extern s32 func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800EF604_ovl01(u8* obj) {
    u8* p;

    if (D_8009A197 != 0) {
        u8* q = D_8009A1F8;
        s32 d = *(s32*)(q + 8) - *(s32*)(q + 0x14);
        d += d / 4;
        *(s32*)(obj + 8) -= d;
    } else {
        *(s16*)(obj + 0xA) -= 0xC;
    }
    p = D_8009A1F8;
    *(s16*)(obj + 0xE) = 0x200 - *(u16*)(p + 0x62);
    func_8002D9EC(obj, 0x100, 0x100);
    if (*(s8*)(obj + 3) == 0) {
        obj[4]++;
    }
}
