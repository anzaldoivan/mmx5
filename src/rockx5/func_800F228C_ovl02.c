#include "types.h"

#define SCR (*(Scr4C**)0x1F80004C)

extern s32 func_8003157C(Ent14C8*, s32, s32);
extern void func_8002DF54(Ent14C8*);
extern Unk800770CC D_800F463C_ovl02;
extern u8 D_800F463E_ovl02;
extern u8 D_800F463F_ovl02;

void func_800F228C_ovl02(Ent14C8* e) {
    s32 i;
    s16 x;

    if (e->flags70 & 4) {
        SCR->cnt88--;
        SCR->box.c = D_800F463E_ovl02;
        e->f20 = 0x38000;
        e->f24 = 0;
        e->state = 9;
    } else if (!(e->flags70 & 2)) {
        i = 0;
        SCR->cnt88--;
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
                e->f20 = 0xFFFC8000;
                e->state = 7;
                SCR->flags83 |= 0x10;
                break;
            }
            if (i == 4) {
                e->state = 2;
                e->f28 = 0;
                e->f2C = 0x1000;
                SCR->box = D_800F463C_ovl02;
                return;
            }
            i++;
        } while (i < 5);
    } else if (SCR->flags83 & 0x10) {
        SCR->box.d = D_800F463F_ovl02;
        SCR->flags83 &= ~0x10;
    }
    func_8002DF54(e);
}
