#include "types.h"

typedef struct Obj0E88 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[14];
    /* 0x15 */ u8 unk15;
} Obj0E88;

#define D_1F80004C (*(Scr0B1C**)0x1F80004C)

extern void func_800171E8(Obj0E88*, s32);

void func_800F0E88_ovl01(Obj0E88* arg0) {
    if (--D_1F80004C->unk80 != 0) {
        return;
    }
    switch (D_1F80004C->unk85 & 0xFE) {
    case 2:
    case 4:
    case 6:
        arg0->unk15 = 0x40;
    case 10:
    case 12:
    case 14:
        if (D_1F80004C->unk85 >= 10) {
            arg0->unk15 = 0;
        }
        func_800171E8(arg0, 4);
        break;
    case 8:
        func_800171E8(arg0, 2);
        break;
    case 18:
    case 20:
    case 22:
        arg0->unk15 = 0;
    case 26:
    case 28:
    case 30:
        if (D_1F80004C->unk85 >= 0x1A) {
            arg0->unk15 = 0x40;
        }
        func_800171E8(arg0, 5);
        break;
    case 24:
        func_800171E8(arg0, 3);
        break;
    case 0:
        arg0->unk15 = 0x40;
        break;
    case 16:
        arg0->unk15 = 0;
        break;
    }
    arg0->unk6++;
}
