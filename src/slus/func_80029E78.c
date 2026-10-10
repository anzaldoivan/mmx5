#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[6];
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u8 pad18[2];
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ u8 pad1C[0x24];
    /* 0x40 */ u16 unk40;
} Obj29E78;

extern s16 D_8009A202;

void func_80029E78(Obj29E78* o) {
    s16 x;
    s16 d;
    s32 t;

    t = o->unk40;
    x = (D_8009A202 >> 1) + t;
    o->unkA = x;
    d = x - o->unk16;
    if (d >= 0) {
        if (d >= 0x10) {
            if (d < 0x148) {
                o->unkA = o->unk16 + 0x10;
            } else {
                o->unkA = x - 0x140;
            }
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d < 0x148) {
                o->unkA = o->unk16 - 0x10;
            } else {
                o->unkA = x + 0x140;
            }
        }
    }
    d = o->unkE - o->unk1A;
    if (d >= 0) {
        if (d >= 0x10) {
            if (d >= 0x148) {
                o->unkE = o->unkE - 0x140;
            } else {
                o->unkE = o->unk1A + 0x10;
            }
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d >= 0x148) {
                o->unkE = o->unkE + 0x140;
            } else {
                o->unkE = o->unk1A - 0x10;
            }
        }
    }
}
