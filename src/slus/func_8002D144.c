#include "types.h"

extern Slot8002D144 D_8009E7A0[96];

Slot8002D144* func_8002D144(void) {
    Slot8002D144* p;
    u8* b;
    s32 i;

    for (p = D_8009E7A0; p < &D_8009E7A0[96]; p++) {
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
