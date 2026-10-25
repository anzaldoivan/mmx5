#include "types.h"

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
