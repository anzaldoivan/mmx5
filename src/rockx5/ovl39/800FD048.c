#include "types.h"
#include "mmx5/object.h"

void func_800FD048_ovl39(EntFD048* arg0) {
    move_object(arg0);
    if (arg0->unk2 == 0 && arg0->unkA >= 0x1290) {
        arg0->unk6++;
    } else if (arg0->unk2 == 1 && arg0->unkA < 0x1191) {
        arg0->unk6++;
    }
}

extern u8 D_800FEB3C_ovl39[][4];

void func_800FD0C4_ovl39(EntFD404* e) {
    u8 t = e->unk7C->unk89;
    if (t == 1) {
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

#define D_800EEC60_ovl00 func_800FD15C_ovl39
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
