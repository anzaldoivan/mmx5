#include "types.h"
#include "mmx5/globals.h"

#define func_8002979C func_80029D48
#include "shared/func_8002979C.c"
#undef func_8002979C

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

void func_80029F70(s16* p) {
    s16 t;
    s16 a;
    s16 d;

    t = D_8009A1F8.h[5] >> 2;
    a = t + p[0x20];
    p[5] = a;
    d = a - p[0xB];
    p[7] = D_8009A1F8.h[7] + p[0x21];
    if (d >= 0) {
        if (d >= 0x10) {
            if (d < 0x148) {
                p[5] = p[0xB] + 0x10;
            } else {
                p[5] = a - 0x140;
            }
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d < 0x148) {
                p[5] = p[0xB] - 0x10;
            } else {
                p[5] = a + 0x140;
            }
        }
    }
    d = p[7] - p[0xD];
    if (d >= 0) {
        if (d >= 0x10) {
            if (d >= 0x148) {
                p[7] = p[7] - 0x140;
            } else {
                p[7] = p[0xD] + 0x10;
            }
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d >= 0x148) {
                p[7] = p[7] + 0x140;
            } else {
                p[7] = p[0xD] - 0x10;
            }
        }
    }
}
