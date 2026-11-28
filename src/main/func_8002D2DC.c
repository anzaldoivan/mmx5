#include "types.h"
#include "mmx5/object.h"

Slot8002D27C* func_8002D2DC(void) {
    Slot8002D27C* p;
    u8* b;
    s32 i;

    for (p = D_800994A0.d27c; p < &D_800994A0.d27c[32]; p++) {
        if (p->active == 0) {
            b = (u8*)p;
            for (i = sizeof(Slot8002D27C) - 1; i != -1; i--) {
                *b++ = 0;
            }
            return p;
        }
    }
    return 0;
}
