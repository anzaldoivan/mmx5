#include "types.h"

typedef struct Ent01A8 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[7];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[9];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ void* unk30;
    /* 0x34 */ u8 pad34[0x1C];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 pad62[5];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x10];
    /* 0x7C */ u8 unk7C;
} Ent01A8;

typedef struct Scr01A8 {
    /* 0x00 */ u8 pad0[0x81];
    /* 0x81 */ u8 unk81;
    /* 0x82 */ u8 pad82[7];
    /* 0x89 */ u8 unk89;
    /* 0x8A */ u8 unk8A;
    /* 0x8B */ u8 unk8B;
    /* 0x8C */ u8 pad8C[2];
    /* 0x8E */ u16 unk8E;
    /* 0x90 */ s32 unk90;
    /* 0x94 */ s32 unk94;
} Scr01A8;

#define D_1F80004C (*(Scr01A8**)0x1F80004C)

extern u8 D_8009A0B4;
extern u8 D_800FD98C_ovl28[];
extern u8 D_800FD9C8_ovl28[];
extern u8 D_800FD9C0_ovl28[];
extern u8 D_800750C0[];
extern s32 func_8002DF78(void);
extern void func_800171E8(Ent01A8*, s32);

void func_800F01A8_ovl28(Ent01A8* e) {
    s32 t = D_8009A0B4;
    s32 r;

    e->unk30 = D_800FD98C_ovl28;
    e->unk16 = 4;
    e->unk20 = 0;
    e->unk24 = 0;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk67 = 0;
    e->unk68 = 0;
    e->unk50 = D_800FD9C8_ovl28;
    e->unk54 = D_800FD9C0_ovl28;
    e->unk58 = D_800750C0;
    e->unk61 = 0;
    e->unk5C = 5;
    e->unk60 = 3;
    e->unk4 = 1;
    e->unk6 = 0;
    e->unk14 = t;
    r = func_8002DF78() & 3;
    t = (s32)D_1F80004C;
    ((Scr01A8*)t)->unk81 = r;
    D_1F80004C->unk89 = 0;
    if (e->unk2 & 0x80) {
        func_800171E8(e, 0);
        e->unk5 = 2;
        e->unk67 = 1;
    } else {
        e->unk15 = 0;
        func_800171E8(e, 0);
        e->unk67 = 0;
        e->unk5 = 3;
    }
    if ((e->unk2 & 0xF) == 1) {
        e->unk4 = 3;
    }
    if (e->unk2 == 3) {
        func_800171E8(e, 1);
        D_1F80004C->unk8A = e->unk6;
        D_1F80004C->unk8B = e->unk7C;
        D_1F80004C->unk8E = e->unkE;
        D_1F80004C->unk90 = e->unk24;
        D_1F80004C->unk94 = e->unk2C;
        e->unk5 = 7;
    }
}
