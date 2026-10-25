#include "types.h"
#include "addr.h"

extern void func_800171E8(Obj*, s32);

void func_800F4900_ovl26(Obj* o) {
    if (--o->timer != 0) {
        return;
    }
    switch (D_1F80004C.scr2074->unk94) {
    case 0:
        func_800171E8(o, 0xC);
        break;
    case 1:
        func_800171E8(o, 0x1C);
        break;
    case 2:
        func_800171E8(o, 0x1F);
        break;
    case 3:
        func_800171E8(o, 0x22);
        break;
    case 4:
        func_800171E8(o, 0x25);
        break;
    case 5:
        func_800171E8(o, 0x28);
        break;
    case 6:
        func_800171E8(o, 0x2B);
        break;
    case 7:
        func_800171E8(o, 0x2E);
        break;
    }
    o->timer = 20;
    o->step++;
}
