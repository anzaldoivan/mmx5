#include "types.h"

typedef struct Obj0E9C {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[3];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0xE];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x37];
    /* 0x67 */ u8 unk67;
} Obj0E9C;

#define D_1F80004C (*(Ctx0F18**)0x1F80004C)

extern void func_800171E8(Obj0E9C*, s32);

void func_800F0E9C_ovl28(Obj0E9C* arg0) {
    arg0->unk67 = 0;
    arg0->unk6++;
    if ((arg0->unk2 & 0xF) == 2) {
        arg0->unk20 = 0;
    } else {
        s32 v = -0x40000;
        if (arg0->unk15 != 0) {
            v = 0x40000;
        }
        arg0->unk20 = v;
    }
    arg0->unk28 = 0;
    arg0->unk24 = 0;
    arg0->unk2C = 0;
    func_800171E8(arg0, 0);
    D_1F80004C->unk80 = 0x3C;
}
