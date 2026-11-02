#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);

void func_800FE564_ovl39(u8* obj) {
    u8* p;

    p = *(u8**)(obj + 0x50);
    obj[0x15] = p[0x15];
    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    switch (p[0x47]) {
    case 0:
        obj[3] = 1;
        if (*(s8*)(obj + 0x5C) != p[0x47]) {
            func_800171E8(obj, 1);
        }
        obj[0x5C] = p[0x47];
        break;
    case 6:
    case 0xB ... 0x11:
        obj[3] = 1;
        if (*(s8*)(p + 0x45) == 8) {
            func_800171E8(obj, 5);
        }
        break;
    default:
        obj[3] = 0;
        break;
    }
    obj[0x5C] = p[0x47];
    func_80017248(obj);
    if (*(s8*)(p + 4) == 2) {
        obj[4]++;
    }
}
