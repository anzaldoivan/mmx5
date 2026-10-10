#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[5];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[9];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ u8 pad34[8];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0xC];
    /* 0x50 */ void* unk50; /* same ObjEF680 shape */
} ObjEF680;

extern s32 func_800171E8(ObjEF680*, s32);
extern u8 D_800F5018_ovl05[];

void func_800EF680_ovl05(ObjEF680* s) {
    ObjEF680* p = s->unk50;

    s->unk3 = 1;
    s->unk20 = 0;
    s->unk28 = 0;
    s->unk24 = 0;
    s->unk2C = 0;
    s->unk16 = 0;
    s->unk40 = p->unk40;
    s->unk42 = p->unk42 & 0x7FFF;
    s->unk30 = p->unk30;
    s->unk3C = p->unk3C;
    s->unk15 = p->unk15;
    s->unk14 = p->unk14;
    func_800171E8(s, 7);

    switch (s->unk2 & 0xFE) {
    case 2:
    case 4:
    case 6:
        s->unkA += (s8)D_800F5018_ovl05[6];
        s->unkE += (s8)D_800F5018_ovl05[7];
        break;
    case 10:
    case 12:
    case 14:
        s->unkA += (s8)D_800F5018_ovl05[4];
        s->unkE += (s8)D_800F5018_ovl05[5];
        break;
    case 8:
        s->unkA += (s8)D_800F5018_ovl05[8];
        s->unkE += (s8)D_800F5018_ovl05[9];
        break;
    case 18:
    case 20:
    case 22:
        s->unkA += (s8)D_800F5018_ovl05[12];
        s->unkE += (s8)D_800F5018_ovl05[13];
        break;
    case 26:
    case 28:
    case 30:
        s->unkA += (s8)D_800F5018_ovl05[14];
        s->unkE += (s8)D_800F5018_ovl05[15];
        break;
    case 24:
        s->unkA += (s8)D_800F5018_ovl05[10];
        s->unkE += (s8)D_800F5018_ovl05[11];
        break;
    default:
        if (s->unk15 & 0x40) {
            s->unkA += (s8)D_800F5018_ovl05[2];
            s->unkE += (s8)D_800F5018_ovl05[3];
        } else {
            s->unkA += (s8)D_800F5018_ovl05[0];
            s->unkE += (s8)D_800F5018_ovl05[1];
        }
        break;
    }
    s->unk4++;
}
