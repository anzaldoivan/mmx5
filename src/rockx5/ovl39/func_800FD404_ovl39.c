#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800FEB3C_ovl39[][4];

void func_800FD404_ovl39(EntFD404* e) {
    animate_object(e);
    if (e->unk45 == 1) {
        u8 t = e->unk7C->unk89;
        if (t == e->unk45) {
            e->unk87 = 6;
            e->unk88 = t;
        }
        if (e->unk7C->unk7 != 0x11) {
            e->unk5 = 7;
        } else {
            e->unk88++;
            e->unk5 = D_800FEB3C_ovl39[e->unk87][e->unk88];
        }
        if (e->unk5 == 2) {
            e->unk82 = 180;
        }
        e->unk6 = 0;
    }
}
