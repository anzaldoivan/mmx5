#include "types.h"

typedef struct Ent15AC {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x14];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0x54];
    /* 0x7C */ s16 unk7C;
} Ent15AC;

extern u8 D_8009A0A0[];
extern s16 D_8009A202;
extern void func_8002DF54(Ent15AC*);

#define PLR ((Ent15AC*)D_8009A0A0)
#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800F15AC_ovl26(Ent15AC* o) {
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
    o->unkA = D_8009A202 + 0x40;
    if (--o->unk7C == -1) {
        o->unk5 = 4;
        o->unk6 = 0;
    }
    if (ABS(PLR->unkA - o->unkA) < 0x21) {
        o->unk6 = 0;
    }
}
