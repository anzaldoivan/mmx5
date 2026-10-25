#include "types.h"

extern s32 func_8002DF78(void);
extern s32 func_8002DFB0(void);
extern s32 func_800171E8(Obj5E5C*, s32);
extern s32 D_80101C4C_ovl04[];
extern s32 D_80101C6C_ovl04[];
extern D_8009A1F8_t D_8009A1F8;

void func_800F5E5C_ovl04(Obj5E5C* o) {
    o->unk3 = 1;
    o->unk16 = 1;
    o->unk4++;
    o->unk7 = 0;
    switch (o->unk2) {
    case 0:
        o->unk47 = 0x38;
        o->unk20 = D_80101C4C_ovl04[func_8002DF78() & 7] / 4;
        o->unk24 = D_80101C6C_ovl04[func_8002DF78() & 7] / 2;
        o->unk2C = 0x2800;
        o->unk28 = 0;
        break;
    case 1:
        o->unkA = D_8009A1F8.unkA + (func_8002DF78() & 0xFFFF) * 2 % 320;
        o->unkE = D_8009A1F8.unkE + 0x104;
        o->unk20 = 0;
        o->unk28 = 0;
        o->unk2C = 0;
        func_800171E8(o, 0x10);
        o->unk24 = 0x20000;
        o->unk24 += func_8002DF78() << 7;
        o->unk7 = func_8002DFB0() % 120;
        break;
    case 2:
        o->unkA = D_8009A1F8.unkA + (func_8002DF78() & 0xFFFF) * 2 % 320;
        o->unkE = D_8009A1F8.unkE + 0x104;
        o->unk20 = 0;
        o->unk28 = 0;
        o->unk2C = 0;
        o->unk24 = 0x10000;
        o->unk24 += func_8002DF78() << 7;
        func_800171E8(o, 0x11);
        o->unk7 = func_8002DFB0() % 120;
        break;
    case 3:
        func_800171E8(o, 0xF);
        o->unk20 = 0;
        o->unk28 = 0;
        o->unk2C = 0;
        o->unk24 = 0x10000;
        o->unk24 += func_8002DF78() << 7;
        o->unk7 = func_8002DFB0() % 10;
        break;
    case 4:
        o->unkA = D_8009A1F8.unkA + (func_8002DF78() & 0xFFFF) * 2 % 360 - 0x28;
        o->unkE = D_8009A1F8.unkE + 0x104;
        o->unk28 = 0;
        o->unk2C = 0;
        o->unk24 = 0x10000;
        o->unk24 += func_8002DF78() << 7;
        func_800171E8(o, 0x11);
        o->unk7 = func_8002DFB0() % 60;
        break;
    case 5:
        o->unkA = D_8009A1F8.unkA - 0x28;
        o->unkE = D_8009A1F8.unkE + (func_8002DF78() & 0xFFFF) * 2 % 240 + 0x14;
        o->unk28 = 0;
        o->unk2C = 0;
        o->unk24 = 0x10000;
        o->unk24 += func_8002DF78() << 7;
        func_800171E8(o, 0x11);
        o->unk7 = func_8002DFB0() % 60;
        break;
    case 7:
        o->unk28 = 0;
        o->unk2C = -0x8000;
        o->unk24 = -0x40000;
        o->unk24 += func_8002DF78() << 7;
        func_800171E8(o, 0x11);
        o->unk7 = 0;
        break;
    case 6:
    case 8:
        o->unk28 = 0;
        func_800171E8(o, 0x1A);
        o->unk2C = -0x8000;
        o->unk24 = -0x40000;
        o->unk24 += func_8002DF78() << 7;
        o->unk7 = func_8002DFB0() % 10;
        break;
    case 9:
        o->unk20 = 0;
        o->unk28 = 0;
        o->unk24 = 0;
        o->unk2C = 0;
        func_800171E8(o, 0x1B);
        break;
    }
}
