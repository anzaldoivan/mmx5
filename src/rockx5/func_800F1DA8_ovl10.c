#include "types.h"
#include "addr.h"

#define SCR D_1F80004C.scr82
extern void func_800171E8(Ent14C8*, s32);
extern void func_8002DF54(Ent14C8*);
extern u8 D_800FB6B2_ovl10;
extern u8 D_800FB6B3_ovl10;

void func_800F1DA8_ovl10(Ent14C8* e) {
    if (e->flags70 & 8) {
        SCR->box.c = D_800FB6B2_ovl10;
        e->f20 = 0x13000;
        e->f24 = 0;
        e->state = 3;
        e->dir = 0x40;
        func_800171E8(e, 9);
    } else if (!(e->flags70 & 2)) {
        e->f20 = 0;
        e->f24 = 0x13000;
        e->state = 0xA;
        e->dir = 0;
        func_800171E8(e, 0xA);
    } else if (SCR->flags82 & 0x10) {
        SCR->box.d = D_800FB6B3_ovl10;
        SCR->flags82 &= ~0x10;
    }
    func_8002DF54(e);
}
