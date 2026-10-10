#include "types.h"

extern Slot8002D144 D_800C94A8[4];

Slot8002D144* func_8002D69C(void) {
    Slot8002D144* p;
    u8* b;
    s32 i;

    for (p = D_800C94A8; p < &D_800C94A8[4]; p++) {
        if (p->active == 0) {
            b = (u8*)p;
            for (i = sizeof(Slot8002D144) - 1; i != -1; i--) {
                *b++ = 0;
            }
            return p;
        }
    }
    return 0;
}
