#include "types.h"
#include "addr.h"

extern void func_800171E8(Ent6864*, s32);
extern Plr1468 D_8009A0A0;
extern u8 D_800FA424_ovl26[];
extern u16 D_800FA478_ovl26[];

void func_800F6864_ovl26(Ent6864* o) {
    Plr1468* plr = &D_8009A0A0;

    o->unk5C = 0;
    o->unk60 = 0;
    o->unk61 = 0;
    o->unk14 = plr->unk14;
    o->unk67 = 0;
    o->unk30 = D_800FA424_ovl26;
    o->unk16 = 6;
    o->unk58 = 0;
    o->unk54 = 0;
    o->unk50 = 0;
    o->unk68 = 0;
    o->unk20 = 0;
    o->unk28 = 0;
    o->unk24 = 0;
    o->unk2C = 0;
    o->unk18 = o->unk8.w;
    o->unk1C = o->unkC.w;
    D_1F80004C.scr80->unk80 = D_800FA478_ovl26[o->unk2];
    switch (o->unk2) {
    case 0:
    case 4:
    case 5:
        o->unk15 = 0;
        func_800171E8(o, 5);
        o->unk2 = 0;
        o->unk8.h.hi += 0xA0;
        break;
    case 1:
    case 6:
        o->unk15 = 1;
        func_800171E8(o, 5);
        o->unk2 = 1;
        o->unk8.h.hi -= 0xA0;
        break;
    case 2:
        o->unk15 = 0;
        func_800171E8(o, 3);
        break;
    case 3:
        o->unk15 = 0;
        func_800171E8(o, 4);
        break;
    }
    o->unk4 = 1;
    o->unk5 = 0;
    o->unk6 = 0;
}
