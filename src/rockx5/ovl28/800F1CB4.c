#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define func_800F15AC_ovl26 func_800F1CB4_ovl28
#include "shared/func_800F15AC_ovl26.c"
#undef func_800F15AC_ovl26

/* Standalone twin of func_800F15AC_ovl26: D_8009A202 + 0x100. */

extern s16 D_8009A202;

#define PLR ((Ent15AC*)g_Player)
#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800F1DD4_ovl28(Ent15AC* o) {
    if (ABS(PLR->unkE - o->unkE) >= 4) {
        if (PLR->unkE >= o->unkE) {
            o->unk24 = -0x10000;
        } else {
            o->unk24 = 0x10000;
        }
    } else {
        o->unk24 = 0;
    }
    move_object(o);
    o->unkA = D_8009A202 + 0x100;
    if (--o->unk7C == -1) {
        o->unk5 = 4;
        o->unk6 = 0;
    }
    if (ABS(PLR->unkA - o->unkA) < 0x21) {
        o->unk6 = 0;
    }
}
