#include "types.h"

extern void func_800171E8(Obj800FD23C*, s32);
extern u8 D_80074E40[];
extern u8 D_80101DB0_ovl07[];
extern u8 D_80101DB4_ovl07[];
extern u8 D_80101DBC_ovl07[];
extern u8 D_80101DC0_ovl07[];
extern u8 D_80101DC8_ovl07[];
extern u8 D_80101DCC_ovl07[];
extern u8 D_80101DD4_ovl07[];
extern u8 D_80101DD8_ovl07[];
extern u8 D_80101DDC_ovl07[];
extern signed char D_800D1C0C;

void func_800FD23C_ovl07(Obj800FD23C* o) {
    o->unk60 = 4;
    o->unk20 = 0;
    o->unk24 = 0;
    o->unk28 = 0;
    o->unk16 = 5;
    o->unk2C = 0;
    o->unk54 = 0;
    o->unk8C = 0;
    o->unk8D = 0;
    o->unk67 = 1;
    o->unk90 = 0xB4;
    o->unk8E = 0;
    o->unk42 &= 0x7FFF;
    func_800171E8(o, 0x11);

    switch (o->state) {
    case 0:
        o->unk20 = 0x38000;
        o->unk24 = 0;
        o->unk58 = D_80074E40;
        o->unk68 = D_80101DCC_ovl07;
        o->unk50 = D_80101DB4_ovl07;
        o->unk54 = D_80101DC0_ovl07;
        func_800171E8(o, 8);
        o->unk15 = 0;
        o->unk05 = 7;
        break;
    case 1:
        o->unk24 = 0x38000;
        o->unk58 = D_80074E40;
        o->unk68 = D_80101DC8_ovl07;
        o->unk20 = 0;
        o->unk50 = D_80101DB0_ovl07;
        o->unk54 = D_80101DBC_ovl07;
        func_800171E8(o, 0xC);
        o->unk15 = 0;
        o->unk05 = 4;
        break;
    case 2:
        o->unk20 = -0x38000;
        o->unk24 = 0;
        o->unk58 = D_80074E40;
        o->unk68 = D_80101DCC_ovl07;
        o->unk50 = D_80101DB4_ovl07;
        o->unk54 = D_80101DC0_ovl07;
        func_800171E8(o, 8);
        o->unk15 = 0x40;
        o->unk05 = 6;
        break;
    case 3:
        o->unk24 = -0x38000;
        o->unk58 = D_80074E40;
        o->unk68 = D_80101DC8_ovl07;
        o->unk20 = 0;
        o->unk50 = D_80101DB0_ovl07;
        o->unk54 = D_80101DBC_ovl07;
        func_800171E8(o, 0xA);
        o->unk15 = 0x40;
        o->unk05 = 5;
        break;
    case 4:
        o->unk16 = 2;
        o->unk68 = 0;
        o->unk50 = D_80101DD4_ovl07;
        func_800171E8(o, 0x10);
        o->unk15 = 0;
        o->unk05 = 8;
        break;
    case 5:
        o->unk16 = 2;
        func_800171E8(o, 0x11);
        o->unk15 = 0;
        o->unk05 = 9;
        break;
    case 6:
        o->unk16 = 2;
        func_800171E8(o, 0x11);
        o->unk15 = 0x40;
        o->unk05 = 9;
        break;
    case 7:
        o->unk68 = 0;
        o->unk50 = D_80101DDC_ovl07;
        o->unk05 = 0xA;
        break;
    case 8:
        o->unk68 = 0;
        o->unk50 = D_80101DD8_ovl07;
        o->unk05 = 0xA;
        break;
    }

    if (D_800D1C0C != 12) {
        o->unk84[0] = 0;
        o->unk84[1] = 0;
    } else {
        o->unk84[0] = -0x1B60;
        o->unk84[1] = -0x440;
    }
    o->unk04 = 1;
    o->unk06 = 0;
    o->unk07 = 0;
    o->unk03 = 0;
}
