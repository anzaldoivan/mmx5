#include "types.h"
#include "addr.h"

void func_800F09F0_ovl28(void) {
    D_1F80004C.scr1090->unk88 = D_1F80004C.scr1090->unk85 & 0xFE;
    switch (D_1F80004C.scr1090->unk85 & 0xFE) {
    case 0:
        D_1F80004C.scr1090->unk86 = 0x1E;
        D_1F80004C.scr1090->unk87 = 2;
        break;
    case 2:
    case 4:
    case 6:
        D_1F80004C.scr1090->unk86 = 0;
        D_1F80004C.scr1090->unk87 = 8;
        break;
    case 8:
        D_1F80004C.scr1090->unk86 = 6;
        D_1F80004C.scr1090->unk87 = 0xA;
        break;
    case 10:
    case 12:
    case 14:
        D_1F80004C.scr1090->unk86 = 8;
        D_1F80004C.scr1090->unk87 = 0x10;
        break;
    case 16:
        D_1F80004C.scr1090->unk86 = 0xE;
        D_1F80004C.scr1090->unk87 = 0x12;
        break;
    case 18:
    case 20:
    case 22:
        D_1F80004C.scr1090->unk86 = 0x10;
        D_1F80004C.scr1090->unk87 = 0x18;
        break;
    case 24:
        D_1F80004C.scr1090->unk86 = 0x16;
        D_1F80004C.scr1090->unk87 = 0x1A;
        break;
    case 26:
    case 28:
    case 30:
        D_1F80004C.scr1090->unk86 = 0x18;
        D_1F80004C.scr1090->unk87 = 0;
        break;
    }
}
