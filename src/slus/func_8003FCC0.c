#include "types.h"

s32 func_8003FCC0(Obj8003FCC0* p, s8 i) {
    s8 v = p->unk9B[i];

    if (v == 0) {
        return 0;
    }
    if (v == 1) {
        p->unkA1 = 0x26;
        return 1;
    }
    if (p->unk94[i] == 0x14) {
        p->unkA1 = 0x2F;
        return 1;
    }
    p->unkA1 = 0x29;
    return 1;
}
