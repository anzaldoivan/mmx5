#include "types.h"

extern void func_80017248(u8* obj);
extern u8 D_8009A0A0[];

void func_800F6F98_ovl26(u8* obj) {
    u8* g;

    if (*(s8*)(*(u8**)(obj + 0x50) + 4) == 2 ||
        (g = D_8009A0A0, ((s8*)g)[0xD4] != 0)) {
        obj[4] = 2;
        obj[5] = 0;
        obj[6] = 0;
        obj[3] = 0;
        return;
    }
    if (g[0xF7] == 0) {
        func_80017248(obj);
    }
    if (*(s8*)(obj + 2) >= 0x10) {
        obj[3] = 1;
        switch (*(s8*)(obj + 2)) {
        case 16:
            *(u16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x54) + 0xA) - 0x18;
            *(u16*)(obj + 0xE) = *(u16*)(*(u8**)(obj + 0x54) + 0xE);
            break;
        case 17:
            *(u16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x54) + 0xA) + 0x18;
            *(u16*)(obj + 0xE) = *(u16*)(*(u8**)(obj + 0x54) + 0xE);
            break;
        case 18:
            *(u16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x54) + 0xA);
            *(u16*)(obj + 0xE) = *(u16*)(*(u8**)(obj + 0x54) + 0xE) - 0x78;
            break;
        case 19:
            *(u16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x54) + 0xA);
            *(u16*)(obj + 0xE) = *(u16*)(*(u8**)(obj + 0x54) + 0xE) + 0x78;
            break;
        }
    }
}
