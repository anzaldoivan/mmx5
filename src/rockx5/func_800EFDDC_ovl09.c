#include "types.h"

extern void func_800171E8(void*, s32);
extern u8 D_800750C0[];
extern X4_Obj D_8009A0A0;
extern u8 D_800FA940_ovl09[];
extern u8 D_800FA878_ovl09[];
extern u8 D_800FA870_ovl09[];
extern u8 D_800FA874_ovl09[];

void func_800EFDDC_ovl09(ObjEFDDC* a0) {
    a0->unk5C = 4;
    a0->unk80 = 0;
    a0->unk84 = 0;
    a0->unk88 = 0;
    a0->unk8C = 0;
    a0->unk90 = 0;
    a0->unk60 = 3;
    a0->unk58 = (s32)D_800750C0;
    a0->unk61 = 0;
    a0->unk14 = D_8009A0A0.bg_offset;
    a0->unk20 = 0;
    a0->unk30 = (s32)D_800FA940_ovl09;
    a0->unk16 = 6;
    a0->unk68 = (s32)D_800FA878_ovl09;
    a0->unk54 = (s32)D_800FA870_ovl09;
    a0->unk24 = 0;
    a0->unk28 = 0;
    a0->unk2C = 0;
    a0->unk67 = 0;
    a0->unk70 = 0;
    a0->unk50 = (s32)D_800FA874_ovl09;
    a0->unk18 = a0->unk8;
    a0->unk1C = a0->unkC;
    switch (a0->unk2) {
    case 0:
        a0->unk15 = 0;
        a0->unk80 = 0;
        a0->unk20 = -0x28000;
        a0->unk5 = 2;
        func_800171E8(a0, 0);
        break;
    case 1:
        a0->unk7A = 1;
        a0->unk15 = 0x40;
        a0->unk80 = 0;
        a0->unk20 = 0x28000;
        a0->unk5 = 4;
        break;
    case 2:
        a0->unk80 = 1;
        a0->unk15 = 0;
        a0->unk20 = -0x28000;
        a0->unk5 = 2;
        func_800171E8(a0, 0);
        break;
    case 3:
        a0->unk7A = 1;
        a0->unk15 = 0x40;
        a0->unk80 = 1;
        a0->unk20 = 0x28000;
        a0->unk5 = 4;
        break;
    case 4:
        a0->unk15 = (D_8009A0A0.x_pos.val < a0->unk8) ? 0 : 0x40;
        a0->unk80 = 1;
        a0->unk5 = 7;
        func_800171E8(a0, 0);
        break;
    }
    a0->unk4 = 1;
    a0->unk6 = 0;
}
