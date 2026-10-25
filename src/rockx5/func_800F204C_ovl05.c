#include "types.h"

extern void func_800171E8(Obj197C*, s32);
extern s32 func_80016490(s32, s32, void*);

void func_800F204C_ovl05(Obj197C* o) {
    switch (o->state) {
    case 0:
    case 1:
    case 2:
        func_800171E8(o, 0x13);
        o->unk92 = 4;
        break;
    case 3:
    case 4:
    case 5:
        func_800171E8(o, 6);
        o->unk92 = 1;
        break;
    }
    o->unk91 = 2;
    func_80016490(2, 0x18, o);
    o->step++;
}
