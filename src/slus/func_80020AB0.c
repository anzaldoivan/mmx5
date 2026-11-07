#include "types.h"

extern s32 func_80013674(void);
extern u8 D_8006FADB;
extern u8 D_8006FADC;
extern u8 D_8006FAE0[];
extern u8 D_8009A428;

void func_80020AB0(u8* obj) {
    u8* p;

    obj[0x45] = 2;
    obj[0x47] = 0x20;
    obj[0x48] = 0x20;
    obj[0x53] = 0x30;
    obj[0x54] = 0x30;
    *(s32*)(obj + 0xAC) = 0x34BC00;
    obj[0xAA] = 5;
    obj[0xAB] = 3;
    obj[0xC2] = 1;
    obj[0xC3] = 2;
    obj[0xC4] = 3;
    obj[0xC5] = 2;
    obj[0xC6] = 2;
    obj[0xC7] = 2;
    obj[0xC8] = 2;
    obj[0xC9] = 2;
    obj[0xCA] = 0;
    obj[0xCB] = 0;
    *(s32*)(obj + 0x1B4) = 0;
    obj[0x110] = D_8006FADB;
    obj[0xA0] = D_8006FADC;
    obj[0] = 1;
    p = D_8006FAE0;
    obj[0x1B8] = p[0];
    obj[0x1B9] = p[2];
    D_8009A428 = 0;
    obj[0xC] = 0xE;
    obj[0xD] = 1;
    func_80013674();
}
