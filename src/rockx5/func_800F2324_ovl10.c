#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8001296C(s32);
extern s32 func_8003D010(s8 dmg);
extern s32 func_8002E198(s32);
extern u8 D_8009A0A0[];

void func_800F2324_ovl10(u8* obj) {
    s16 old;
    s32 m;

    func_80017248(obj);
    if (--*(s16*)(obj + 0x92) == 0) {
        func_8001296C(8);
        func_8003D010(1);
        *(s16*)(obj + 0x92) = 0x3C;
    }
    old = *(s16*)(obj + 0x90);
    m = D_8009A0A0[0x5C] & 0x7F;
    if (m != 0) {
        *(u16*)(obj + 0x90) += func_8002E198(m);
    }
    if (old != *(s16*)(obj + 0x90)) {
        *(u16*)(obj + 0x42) |= 0x8000;
    } else {
        *(u16*)(obj + 0x42) &= 0x7FFF;
    }
    if ((*(s16*)(obj + 0x90) >= 0x20 || (s8)D_8009A0A0[0xCA] == 0) &&
        (D_8009A0A0[0x5C] & 0x7F)) {
        obj[0x62] = 0;
        *(u16*)(obj + 0x42) &= 0x7FFF;
        D_8009A0A0[0xCA] = 0;
        obj[4] = 4;
        obj[5] = 0;
    }
}
