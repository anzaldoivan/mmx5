#include "types.h"

extern u8 D_800FFBC0_ovl35[];
extern u8 D_800FF998_ovl35[];
extern u8 D_80074DA0[];
extern s16 D_800FFCA2_ovl35;
extern s16 D_800FFCA4_ovl35;
extern s16 D_800FFCA6_ovl35;
extern s16 D_800FFCA8_ovl35;
extern s16 D_800FFCAA_ovl35;
extern s16 D_800FFCAC_ovl35;
extern s16 D_800FFCAE_ovl35;
extern s16 D_800FFCB0_ovl35;
extern s16 D_800FFCB2_ovl35;
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_800171E8(Ent48B0*, s32);

// from rockx5 800FCDBC (byte twin of 800F48B0_ovl09): child init beside the parent, aims at a per-slot target point and launches
void func_800FCDBC_ovl35(Ent48B0* e) {
    Ent48B0* p = e->unk7C;
    s32 a;
    s32 t;

    e->unk40 = p->unk40;
    e->unk42 = p->unk42 & 0x7FFF;
    e->unk30 = D_800FFBC0_ovl35;
    e->unk3C = p->unk3C;
    e->unk16 = 1;
    e->unk14 = 0;
    e->unk50 = D_800FF998_ovl35;
    e->unk15 = 0;
    e->unk67 = 0;
    e->unk3 = 0;
    e->unk68 = 0;
    e->unk54 = 0;
    e->unk58 = D_80074DA0;
    if (p->unk15 == 0) {
        e->unkA = p->unkA - 0x20;
        e->unkE = p->unkE;
        t = e->unk2;
        switch (t) {
        case 7:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCAE_ovl35 - e->unkA);
            e->unk8C = D_800FFCAE_ovl35;
            break;
        case 8:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCAC_ovl35 - e->unkA);
            e->unk8C = D_800FFCAC_ovl35;
            break;
        case 9:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCAA_ovl35 - e->unkA);
            e->unk8C = D_800FFCAA_ovl35;
            break;
        case 10:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCA8_ovl35 - e->unkA);
            e->unk8C = D_800FFCA8_ovl35;
            break;
        case 11:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCA6_ovl35 - e->unkA);
            e->unk8C = D_800FFCA6_ovl35;
            break;
        case 12:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCA4_ovl35 - e->unkA);
            e->unk8C = D_800FFCA4_ovl35;
            break;
        case 13:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCA2_ovl35 - e->unkA);
            e->unk8C = D_800FFCA2_ovl35;
            break;
        case 6:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCB0_ovl35 - e->unkA);
            e->unk8C = D_800FFCB0_ovl35;
            break;
        }
    } else {
        e->unkA = p->unkA + 0x1C;
        e->unkE = p->unkE;
        t = e->unk2;
        switch (t) {
        case 6:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCA2_ovl35 - e->unkA);
            e->unk8C = D_800FFCA2_ovl35;
            break;
        case 7:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCA4_ovl35 - e->unkA);
            e->unk8C = D_800FFCA4_ovl35;
            break;
        case 8:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCA6_ovl35 - e->unkA);
            e->unk8C = D_800FFCA6_ovl35;
            break;
        case 9:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCA8_ovl35 - e->unkA);
            e->unk8C = D_800FFCA8_ovl35;
            break;
        case 10:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCAA_ovl35 - e->unkA);
            e->unk8C = D_800FFCAA_ovl35;
            break;
        case 11:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCAC_ovl35 - e->unkA);
            e->unk8C = D_800FFCAC_ovl35;
            break;
        case 12:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCAE_ovl35 - e->unkA);
            e->unk8C = D_800FFCAE_ovl35;
            break;
        case 13:
            a = ratan2(D_800FFCB2_ovl35 - e->unkE, D_800FFCB0_ovl35 - e->unkA);
            e->unk8C = D_800FFCB0_ovl35;
            break;
        }
    }
    e->unk20 = rcos(a) * 0xC0;
    e->unk24 = -rsin(a) * 0xC0;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk5C = 1;
    e->unk60 = 5;
    func_800171E8(e, 8);
    e->unk84 = 0xF5;
    e->unk5 = 0;
    e->unk4++;
}
