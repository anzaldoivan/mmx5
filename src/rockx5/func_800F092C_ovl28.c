#include "types.h"

// from rockx5 800F092C
typedef struct {
    u8 pad0[2];
    signed char unk2;
    u8 pad3[2];
    signed char unk5;
    u8 unk6;
    u8 pad7[3];
    s16 unkA;
    u8 padC[0x67 - 0xC];
    signed char unk67;
} Obj092C;

// from rockx5 800F092C
typedef struct {
    u8 pad0[0x81];
    signed char unk81;
    u8 pad82[0x89 - 0x82];
    u8 unk89;
} Scr092C;

#define D_1F80004C (*(Scr092C**)0x1F80004C)

extern s16 D_800FD9CC_ovl28[];
extern s16 D_8009A0AA;

void func_800F092C_ovl28(Obj092C* arg0) {
    Scr092C* s;
    s16 lim;
    s32 d;

    if (arg0->unk67 != 0) {
        return;
    }
    if (arg0->unk5 == 4) {
        return;
    }
    if (arg0->unk5 == 5) {
        return;
    }
    s = D_1F80004C;
    lim = D_800FD9CC_ovl28[s->unk81];
    if (arg0->unk2 == 3) {
        if (s->unk89 == 0) {
            arg0->unk5 = 4;
            arg0->unk6 = 0;
        } else {
            s->unk89--;
        }
        return;
    }
    d = D_8009A0AA - arg0->unkA;
    if ((d >= 0) ? (d <= lim) : (arg0->unkA - D_8009A0AA <= lim)) {
        arg0->unk5 = 4;
        arg0->unk6 = 0;
    }
}
