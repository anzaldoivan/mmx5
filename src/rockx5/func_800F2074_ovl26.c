#include "types.h"
#include "addr.h"

extern s32 func_8002DF78(void);
extern void func_800171E8(Ent2074*, s32);
extern void func_8003D29C(s32, s32);
extern s32 D_800F9634_ovl26[];
extern s32 D_800F9E30_ovl26[];
extern s32 D_800761A0[];
extern u8 D_8009A0B4;
extern u32* D_80098118;

void func_800F2074_ovl26(Ent2074* o) {
    o->unk4 = 1;
    o->unk6 = 0;
    o->unk60 = 0x20;
    o->unk62 = 0;
    o->unk54 = 0;
    o->unk50 = 0;
    o->unk68 = 0;
    if (o->unk2 == 1) {
        D_1F80004C.scr2074->unk94 = func_8002DF78() & 7;
        if (D_1F80004C.scr2074->unk94 == 2 || D_1F80004C.scr2074->unk94 == 7) {
            D_1F80004C.scr2074->unk94 = 0;
        }
        D_1F80004C.scr2074->unk80->unk8F = 0;
        D_1F80004C.scr2074->unk80->unk88 = 0;
        D_1F80004C.scr2074->unk80->unk92 = 1;
        o->unk54 = &D_800F9634_ovl26[D_1F80004C.scr2074->unk94];
        switch (D_1F80004C.scr2074->unk94) {
        case 0:
            func_800171E8(o, 0xB);
            break;
        case 1:
            func_800171E8(o, 0x1B);
            break;
        case 2:
            func_800171E8(o, 0x1E);
            break;
        case 3:
            func_800171E8(o, 0x21);
            break;
        case 4:
            func_800171E8(o, 0x24);
            break;
        case 5:
            func_800171E8(o, 0x27);
            break;
        case 6:
            func_800171E8(o, 0x2A);
            break;
        case 7:
            func_800171E8(o, 0x2D);
            break;
        }
        o->unk16 = 5;
        o->unk14 = D_8009A0B4;
        o->unk58 = D_800761A0;
        o->unk5 = 6;
    } else if (o->unk2 == 2) {
        o->unk54 = D_800F9634_ovl26;
        func_800171E8(o, 0xB);
        o->unk16 = 5;
        o->unk14 = D_8009A0B4;
        o->unk58 = D_800761A0;
        o->unk5 = 6;
        o->unk6 = 9;
    } else {
        o->unk5C = 0;
        o->unk40 = (*D_80098118 >> 7) + 0xB0;
        o->unk14 = D_8009A0B4;
        o->unk16 = 6;
        o->unk15 = 0;
        o->unk3 = 0;
        o->unk58 = D_800761A0;
        o->unk61 = 0;
        func_8003D29C(0x14, 0x40);
        o->unkA = 0xA10;
        o->unkE = 0x1260;
        o->unk18 = 0xA10;
        o->unk1C = 0x1260;
        o->unk20 = 0;
        o->unk24 = 0;
        o->unk28 = 0;
        o->unk2C = 0;
        o->unk30 = D_800F9E30_ovl26;
        D_1F80004C.scr2074->unk8D = 0;
        D_1F80004C.scr2074->unk90 = 0;
        D_1F80004C.scr2074->unk91 = 0;
        D_1F80004C.scr2074->unk92 = 0;
        D_1F80004C.scr2074->unk93 = 0;
        D_1F80004C.scr2074->unk88 = 0;
        D_1F80004C.scr2074->unk96 = 0;
        D_1F80004C.scr2074->unk97 = 0;
        D_1F80004C.scr2074->unk8F = 0;
        o->unk5 = 2;
        o->unk7 = 0;
        o->unk3 = 0;
        func_800171E8(o, 0x19);
    }
}
