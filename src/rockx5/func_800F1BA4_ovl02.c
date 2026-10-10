#include "types.h"

#define SCR (*(Scr4C**)0x1F80004C)

extern s32 func_8003157C(Ent14C8*, s32, s32);
extern void func_8002DF54(Ent14C8*);
extern Unk800770CC D_800F463C_ovl02;
extern u8 D_800F463E_ovl02;
extern u8 D_800F463F_ovl02;

void func_800F1BA4_ovl02(Ent14C8* e) {
    s32 i;
    s16 x;

    if (e->flags70 & 2) {
        SCR->cnt88--;
        SCR->box.d = D_800F463F_ovl02;
        e->f20 = 0;
        e->f24 = 0x38000;
        e->state = 10;
    } else if (!(e->flags70 & 8)) {
        i = 0;
        SCR->cnt88--;
        e->f20 = 0;
        do {
            if (e->dir) {
                x = e->x - SCR->box.a + SCR->box.c;
            } else {
                x = e->x + SCR->box.a + SCR->box.c;
            }
            if ((u8)func_8003157C(e, x + i,
                                  (s16)(e->y + SCR->box.b + SCR->box.d) + 1)) {
                SCR->box.c += i;
                e->f24 = 0xFFFC8000;
                e->state = 8;
                SCR->flags83 |= 1;
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
    } else if (SCR->flags83 & 1) {
        SCR->box.c = D_800F463E_ovl02;
        SCR->flags83 &= ~1;
    }
    func_8002DF54(e);
}
