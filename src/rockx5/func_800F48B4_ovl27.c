/* Standalone twin of func_800F15AC_ovl26 (src/shared/func_800F15AC_ovl26.c): D_8009A202 + 0x100. */
#include "types.h"

extern u8 D_8009A0A0[];
extern s16 D_8009A202;
extern void func_8002DF54(Ent15AC*);

#define PLR ((Ent15AC*)D_8009A0A0)
#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800F48B4_ovl27(Ent15AC* o) {
    if (ABS(PLR->unkE - o->unkE) >= 4) {
        if (PLR->unkE >= o->unkE) {
            o->unk24 = -0x10000;
        } else {
            o->unk24 = 0x10000;
        }
    } else {
        o->unk24 = 0;
    }
    func_8002DF54(o);
    o->unkA = D_8009A202 + 0x100;
    if (--o->unk7C == -1) {
        o->unk5 = 4;
        o->unk6 = 0;
    }
    if (ABS(PLR->unkA - o->unkA) < 0x21) {
        o->unk6 = 0;
    }
}
