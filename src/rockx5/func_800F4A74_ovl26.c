#include "types.h"
#include "addr.h"

extern void func_800171E8(Obj*, s32);
extern void func_80017248(Obj*);

void func_800F4A74_ovl26(Obj* o) {
    func_80017248(o);
    if (--o->timer != 0) {
        return;
    }
    switch (D_1F80004C.scr2074->unk94) {
    case 0:
        func_800171E8(o, 0xD);
        break;
    case 1:
        func_800171E8(o, 0x1D);
        break;
    case 2:
        func_800171E8(o, 0x20);
        break;
    case 3:
        func_800171E8(o, 0x23);
        break;
    case 4:
        func_800171E8(o, 0x26);
        break;
    case 5:
        func_800171E8(o, 0x29);
        break;
    case 6:
        func_800171E8(o, 0x2C);
        break;
    case 7:
        func_800171E8(o, 0x2F);
        break;
    }
    o->step++;
}
