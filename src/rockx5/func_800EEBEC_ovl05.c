#include "types.h"

#define G (*(u8**)0x1F80004C)

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ s8 unk4;
    /* 0x05 */ s8 unk5;
    /* 0x06 */ s8 unk6;
    /* 0x07 */ u8 pad7[0xD];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ s8 unk16;
    /* 0x17 */ u8 pad17[0x19];
    /* 0x30 */ void* unk30;
    /* 0x34 */ u8 pad34[0x1C];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ s8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 pad62[6];
    /* 0x68 */ void* unk68;
} ObjEEBEC;

extern u8 D_8009A0A0[];
extern u8 D_800F4DE8_ovl05[];
extern u8 D_800F4E38_ovl05[];
extern u8 D_800750C0[];
extern u8 D_800F4E7C_ovl05[][16];
extern u8 D_800F4E3C_ovl05[][16];
extern s8 D_800F4EC0_ovl05[][32];
extern s8 func_8002E024(ObjEEBEC*, u8*);
extern void func_800171E8(ObjEEBEC*, s32);

void func_800EEBEC_ovl05(ObjEEBEC* s) {
    u8 t = D_8009A0A0[0x14];

    s->unk30 = D_800F4DE8_ovl05;
    s->unk16 = 3;
    s->unk68 = D_800F4E38_ovl05;
    s->unk58 = D_800750C0;
    s->unk5C = 4;
    s->unk15 = 0;
    s->unk14 = t;
    s->unk50 = D_800F4E7C_ovl05[s->unk2];
    s->unk54 = D_800F4E3C_ovl05[s->unk2];
    s->unk61 = 0;
    s->unk60 = 3;
    G[0x84] = 0;
    G[0x85] = 0;
    if (s->unk2 >= 5) {
        s->unk2 = 0;
    }
    if (s->unk2 == 2) {
        s->unk15 = 0x40;
    } else {
        s->unk15 = 0;
    }
    G[0x86] = func_8002E024(s, D_8009A0A0);
    func_800171E8(s, D_800F4EC0_ovl05[s->unk2][(s8)G[0x86]]);
    s->unk4 = 1;
    s->unk5 = 2;
    s->unk6 = 0;
}
