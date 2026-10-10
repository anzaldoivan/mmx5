#include "types.h"

typedef struct {
    signed char x;
    signed char y;
} OffF1D74;

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char unk2;
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
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[6];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ void* unk68;
    /* 0x6C */ u8 pad6C[0x10];
    /* 0x7C */ void* unk7C; /* an EntF1D74 */
} EntF1D74;

extern u8 D_800FC824_ovl01[];
extern u8 D_800FC81C_ovl01[];
extern u8 D_80074DA0[];
extern OffF1D74 D_800FC828_ovl01[];

extern void func_800171E8(EntF1D74*, s32);

void func_800F1D74_ovl01(EntF1D74* e) {
    EntF1D74* p;

    e->unk3 = 1;
    e->unk68 = D_800FC824_ovl01;
    e->unk54 = D_800FC81C_ovl01;
    e->unk50 = D_800FC81C_ovl01;
    e->unk4++;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk67 = 0;
    e->unk16 = 1;
    e->unk58 = D_80074DA0;
    p = e->unk7C;
    e->unk40 = p->unk40;
    e->unk42 = p->unk42 & 0x7FFF;
    e->unk30 = p->unk30;
    e->unk3C = p->unk3C;
    e->unk15 = p->unk15;
    e->unk14 = p->unk14;
    e->unk60 = 3;
    e->unk5C = 1;
    e->unk20 *= 2;
    e->unk24 *= 2;
    switch (e->unk2 & 0xFE) {
    case 2:
    case 4:
    case 6:
        e->unkA += D_800FC828_ovl01[3].x;
        e->unkE += D_800FC828_ovl01[3].y;
        break;
    case 10:
    case 12:
    case 14:
        e->unkA += D_800FC828_ovl01[2].x;
        e->unkE += D_800FC828_ovl01[2].y;
        break;
    case 8:
        e->unkA += D_800FC828_ovl01[4].x;
        e->unkE += D_800FC828_ovl01[4].y;
        break;
    case 18:
    case 20:
    case 22:
        e->unkA += D_800FC828_ovl01[6].x;
        e->unkE += D_800FC828_ovl01[6].y;
        break;
    case 26:
    case 28:
    case 30:
        e->unkA += D_800FC828_ovl01[7].x;
        e->unkE += D_800FC828_ovl01[7].y;
        break;
    case 24:
        e->unkA += D_800FC828_ovl01[5].x;
        e->unkE += D_800FC828_ovl01[5].y;
        break;
    default:
        if (e->unk15 & 0x40) {
            e->unkA += D_800FC828_ovl01[1].x;
            e->unkE += D_800FC828_ovl01[1].y;
        } else {
            e->unkA += D_800FC828_ovl01[0].x;
            e->unkE += D_800FC828_ovl01[0].y;
        }
        break;
    }
    func_800171E8(e, 6);
}
