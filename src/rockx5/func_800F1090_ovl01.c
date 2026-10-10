#include "types.h"

// from rockx5 800F1090
typedef struct Scr1090 {
    /* 0x00 */ u8 pad0[0x85];
    /* 0x85 */ signed char unk85;
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
    /* 0x88 */ u8 unk88;
} Scr1090;

#define D_1F80004C (*(Scr1090**)0x1F80004C)

void func_800F1090_ovl01(void) {
    D_1F80004C->unk88 = D_1F80004C->unk85 & 0xFE;
    switch (D_1F80004C->unk85 & 0xFE) {
    case 0:
        D_1F80004C->unk86 = 0x1E;
        D_1F80004C->unk87 = 2;
        break;
    case 2:
    case 4:
    case 6:
        D_1F80004C->unk86 = 0;
        D_1F80004C->unk87 = 8;
        break;
    case 8:
        D_1F80004C->unk86 = 6;
        D_1F80004C->unk87 = 0xA;
        break;
    case 10:
    case 12:
    case 14:
        D_1F80004C->unk86 = 8;
        D_1F80004C->unk87 = 0x10;
        break;
    case 16:
        D_1F80004C->unk86 = 0xE;
        D_1F80004C->unk87 = 0x12;
        break;
    case 18:
    case 20:
    case 22:
        D_1F80004C->unk86 = 0x10;
        D_1F80004C->unk87 = 0x18;
        break;
    case 24:
        D_1F80004C->unk86 = 0x16;
        D_1F80004C->unk87 = 0x1A;
        break;
    case 26:
    case 28:
    case 30:
        D_1F80004C->unk86 = 0x18;
        D_1F80004C->unk87 = 0;
        break;
    }
}
