/* Shared body (DK-5), from the banked draft of func_8002D33C by tools/wave/gate.py rescan. */
#include "types.h"

extern Slot8002D27C D_800D1F40[];
extern Slot8002D27C D_800D4EE0[];
extern Slot8002D27C D_800D4F40[];

Slot8002D27C* DEDUP_NAME(Slot8002D27C* p, s32 backward) {
    u8* q;
    s32 i;

    if (backward == 0) {
        if (p == 0) {
            p = D_800D1F40;
        } else {
            p++;
        }
        for (; p < D_800D4F40; p++) {
            if (p->active == 0) {
                q = (u8*)p;
                for (i = sizeof(Slot8002D27C) - 1; i != -1; i--) {
                    *q++ = 0;
                }
                return p;
            }
        }
    } else {
        if (p == 0) {
            p = D_800D4EE0;
        } else {
            if (p == D_800D1F40) {
                return 0;
            }
            p--;
        }
        for (; p >= D_800D1F40; p--) {
            if (p->active == 0) {
                q = (u8*)p;
                for (i = sizeof(Slot8002D27C) - 1; i != -1; i--) {
                    *q++ = 0;
                }
                return p;
            }
        }
    }
    return 0;
}
