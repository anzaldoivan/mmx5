#include "types.h"
#include "mmx5/object.h"

extern Slot8002D0E4 D_80096D28[];

Slot8002D0E4* func_8002D43C(Slot8002D0E4* p, s32 backward) {
    u8* q;
    s32 i;

    if (backward == 0) {
        if (p == 0) {
            p = D_80094398.d0e4;
        } else {
            p++;
        }
        for (; p < g_projectiles.d0e4; p++) {
            if (p->active == 0) {
                q = (u8*)p;
                for (i = sizeof(Slot8002D0E4) - 1; i != -1; i--) {
                    *q++ = 0;
                }
                return p;
            }
        }
    } else {
        if (p == 0) {
            p = D_80096D28;
        } else {
            if (p == D_80094398.d0e4) {
                return 0;
            }
            p--;
        }
        for (; p >= D_80094398.d0e4; p--) {
            if (p->active == 0) {
                q = (u8*)p;
                for (i = sizeof(Slot8002D0E4) - 1; i != -1; i--) {
                    *q++ = 0;
                }
                return p;
            }
        }
    }
    return 0;
}
