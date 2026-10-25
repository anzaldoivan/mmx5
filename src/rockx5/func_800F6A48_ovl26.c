#include "types.h"

extern void func_800171E8(Ent6A48*, s32);
extern void func_800F7664_ovl26(Ent6A48*, s16, s16, u8);
extern void func_800F7734_ovl26(Ent6A48*, s32);
extern u8 D_800FA4A4_ovl26[];
extern u8 D_800FA4A8_ovl26[];
extern u8 D_800FA4AC_ovl26[];
extern u8 D_800FA4B0_ovl26[];
extern u8 D_800FA4B4_ovl26[];
extern u8 D_800FA4B8_ovl26[];
extern u8 D_800FA4BC_ovl26[];
extern u8 D_800FA4C0_ovl26[];
extern u8 D_800FA4C4_ovl26[];
extern u8 D_800FA4C8_ovl26[];

void func_800F6A48_ovl26(Ent6A48* o) {
    o->unk60 = 0x7F;
    o->unk5C = 0;
    o->unk16 = 7;
    o->unk20 = 0;
    o->unk24 = 0;
    o->unk28 = 0;
    o->unk2C = 0;
    o->unk67 = 1;
    o->unk54 = 0;
    switch (o->unk2) {
    case 0:
        func_800171E8(o, 0xF);
        o->unk20 = -0x58000;
        o->unk50 = D_800FA4A4_ovl26;
        o->unk68 = D_800FA4AC_ovl26;
        func_800F7664_ovl26(o, o->unk8.h.hi - 0x10, o->unkC.h.hi, o->unk2);
        func_800F7734_ovl26(o, 0x10);
        o->unk5 = 0;
        o->unk8.h.hi += 0x10;
        break;
    case 1:
        func_800171E8(o, 0x10);
        o->unk50 = D_800FA4A8_ovl26;
        o->unk5 = 1;
        break;
    case 2:
        func_800171E8(o, 0xF);
        o->unk20 = 0x58000;
        o->unk50 = D_800FA4B0_ovl26;
        o->unk68 = D_800FA4B8_ovl26;
        func_800F7664_ovl26(o, o->unk8.h.hi + 0x10, o->unkC.h.hi, o->unk2);
        func_800F7734_ovl26(o, 0x11);
        o->unk5 = 0;
        o->unk8.h.hi -= 0x10;
        break;
    case 3:
        func_800171E8(o, 0x10);
        o->unk50 = D_800FA4B4_ovl26;
        o->unk5 = 1;
        break;
    case 4:
        func_800171E8(o, 0xC);
        o->unk24 = 0x58000;
        o->unk50 = D_800FA4BC_ovl26;
        o->unk68 = D_800FA4C0_ovl26;
        func_800F7664_ovl26(o, o->unk8.h.hi, o->unkC.h.hi - 0x10, o->unk2);
        func_800F7734_ovl26(o, 0x12);
        o->unk5 = 0;
        o->unkC.h.hi += 0x70;
        break;
    case 6:
        func_800171E8(o, 0xD);
        o->unk24 = -0x58000;
        o->unk50 = D_800FA4C4_ovl26;
        o->unk68 = D_800FA4C8_ovl26;
        func_800F7664_ovl26(o, o->unk8.h.hi, o->unkC.h.hi + 0x10, o->unk2);
        func_800F7734_ovl26(o, 0x13);
        o->unk5 = 0;
        o->unkC.h.hi -= 0x70;
        break;
    }
    o->unk4 = 1;
    o->unk6 = 0;
    o->unk7 = 0;
    o->unk3 = 0;
}
