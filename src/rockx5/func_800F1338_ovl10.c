#include "types.h"
#include "addr.h"

#define SCR D_1F80004C.scr82
extern s32 func_8003157C(Ent14C8*, s32, s32);
extern void func_800171E8(Ent14C8*, s32);
extern void func_8002DF54(Ent14C8*);
extern Unk800770CC D_800FB6B0_ovl10;
extern u8 D_800FB6B3_ovl10;

void func_800F1338_ovl10(Ent14C8* e) {
    s32 i;
    s16 x;

    if (e->flags70 & 4) {
        e->f20 = 0;
        e->f24 = 0xFFFED000;
        e->state = 4;
        e->dir = 0;
        func_800171E8(e, 0xB);
    } else if (!(e->flags70 & 2)) {
        i = 0;
        e->f24 = 0;
        do {
            if (e->dir) {
                x = e->x - SCR->box.a - SCR->box.c;
            } else {
                x = e->x + SCR->box.a - SCR->box.c;
            }
            if ((u8)func_8003157C(e, x - 1,
                                  (s16)(e->y + SCR->box.b + SCR->box.d) + i)) {
                SCR->box.d += i;
                e->f20 = 0xFFFED000;
                e->state = 7;
                SCR->flags82 |= 0x10;
                e->dir = 0;
                func_800171E8(e, 8);
                break;
            }
            if ((u8)i == 4) {
                e->state = 2;
                e->f28 = 0;
                e->f2C = 0x1000;
                SCR->box = D_800FB6B0_ovl10;
            }
            i++;
        } while (i < 5);
    } else if (SCR->flags82 & 0x10) {
        SCR->box.d = D_800FB6B3_ovl10;
        SCR->flags82 &= ~0x10;
    }
    func_8002DF54(e);
}
