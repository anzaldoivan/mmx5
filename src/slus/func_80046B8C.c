#include "types.h"

extern u8 D_8009A0A0[];
extern s32 D_8009A420;
extern void func_80017248(u8* obj);

void func_80046B8C(u8* obj) {
    u8* g = D_8009A0A0;
    s32 t;

    *(u16*)(obj + 0xA) = *(u16*)(g + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(g + 0xE);
    func_80017248(obj);
    if ((D_8009A420 & 7) == 0) {
        obj[0x64]++;
    }
    t = *(u16*)(obj + 0x8C) + 1;
    *(u16*)(obj + 0x8C) = t;
    if ((s16)t >= 0x1A5) {
        obj[4] = 2;
    } else if ((s16)t >= 0x191) {
        if (t & 1) {
            obj[3] = 0;
        } else {
            obj[3] = 1;
        }
    } else if ((s16)t == 0x190) {
        *(s32*)(obj + 0x50) = 0;
    }
}
