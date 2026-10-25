#include "types.h"
#include "addr.h"

extern u8 D_8009A0A0[];
extern u8 D_800FC770_ovl01[];
extern s8 func_8002E024(Obj0B1C*, u8*);
extern void func_800171E8(Obj0B1C*, s32);

void func_800F0B1C_ovl01(Obj0B1C* arg0) {
    if (--D_1F80004C.scr0b1c->unk80 != 0) {
        return;
    }
    if (((Ent*)D_8009A0A0)->y - arg0->unkA > 0) {
        arg0->unk15 = 0x40;
    }
    D_1F80004C.scr0b1c->unk85 = func_8002E024(arg0, D_8009A0A0);
    if (arg0->unk2 == 3) {
        D_1F80004C.scr0b1c->unk85 = D_800FC770_ovl01[D_1F80004C.scr0b1c->unk85];
    }
    switch (D_1F80004C.scr0b1c->unk85 & 0xFE) {
    case 2:
    case 4:
    case 6:
        arg0->unk15 = 0x40;
    case 10:
    case 12:
    case 14:
        if (D_1F80004C.scr0b1c->unk85 >= 10) {
            arg0->unk15 = 0;
        }
        func_800171E8(arg0, 4);
        break;
    case 8:
        func_800171E8(arg0, 2);
        break;
    case 18:
    case 20:
    case 22:
        arg0->unk15 = 0;
    case 26:
    case 28:
    case 30:
        if (D_1F80004C.scr0b1c->unk85 >= 0x1A) {
            arg0->unk15 = 0x40;
        }
        func_800171E8(arg0, 5);
        break;
    case 24:
        func_800171E8(arg0, 3);
        break;
    case 0:
        func_800171E8(arg0, 1);
        arg0->unk15 = 0x40;
        break;
    case 16:
        func_800171E8(arg0, 1);
        arg0->unk15 = 0;
        break;
    }
    arg0->unk6++;
}
