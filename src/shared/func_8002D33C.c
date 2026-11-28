#include "types.h"
#include "mmx5/object.h"

extern Slot8002D27C D_800D4EE0[];

Slot8002D27C* func_8002D33C(Slot8002D27C* p, s32 backward) {
    u8* q;
    s32 i;

    if (backward == 0) {
        if (p == 0) {
            p = D_800D1F40.d27c;
        } else {
            p++;
        }
        for (; p < D_800D4F40.d27c; p++) {
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
            if (p == D_800D1F40.d27c) {
                return 0;
            }
            p--;
        }
        for (; p >= D_800D1F40.d27c; p--) {
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
