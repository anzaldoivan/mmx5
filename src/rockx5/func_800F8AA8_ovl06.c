#include "types.h"

typedef struct Obj8AA8 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x20];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
} Obj8AA8;

extern void func_800171E8(Obj8AA8*, s32);
extern s32 D_800FF1DC_ovl06[];
extern s32 D_800FF1E0_ovl06[];
extern s16 D_800FF94C_ovl06;
extern s16 D_8009A0AA;
extern s16 D_800FF4FC_ovl06[];

void func_800F8AA8_ovl06(Obj8AA8* o) {
    s32 d;

    func_800171E8(o, 0x13);
    o->unk50 = D_800FF1DC_ovl06;
    o->unk54 = D_800FF1E0_ovl06;
    if (D_8009A0AA > D_800FF94C_ovl06 + 0x1260) {
        o->unk15 = 0x40;
        o->unk20 = -0x60000;
        d = D_800FF4FC_ovl06[0] + D_800FF94C_ovl06 - o->unkA;
        if (d < 0) {
            d = o->unkA - (D_800FF4FC_ovl06[0] + D_800FF94C_ovl06);
        }
    } else {
        o->unk15 = 0;
        o->unk20 = 0x60000;
        d = D_800FF4FC_ovl06[1] + D_800FF94C_ovl06 - o->unkA;
        if (d < 0) {
            d = o->unkA - (D_800FF4FC_ovl06[1] + D_800FF94C_ovl06);
        }
    }
    if (d < 7) {
        d = 1;
    } else {
        d = d / 6;
    }
    o->unk28 = 0;
    o->unk2C = 0xC0000 / d;
    o->unk24 = 0x60000;
    o->unk6++;
}
