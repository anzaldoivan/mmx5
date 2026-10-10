#include "types.h"

extern Slot8002D0E4 D_80094398[96];
extern Slot8002D0E4 D_80096D28[];
extern Slot8002D0E4 D_80096D98[];

Slot8002D0E4* func_8002D43C(Slot8002D0E4* p, s32 backward) {
    u8* q;
    s32 i;

    if (backward == 0) {
        if (p == 0) {
            p = D_80094398;
        } else {
            p++;
        }
        for (; p < D_80096D98; p++) {
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
            if (p == D_80094398) {
                return 0;
            }
            p--;
        }
        for (; p >= D_80094398; p--) {
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
