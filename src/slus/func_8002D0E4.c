#include "types.h"

extern Slot8002D0E4 D_80094398[96];

Slot8002D0E4* func_8002D0E4(void) {
    Slot8002D0E4* p;
    u8* b;
    s32 i;

    for (p = D_80094398; p < &D_80094398[96]; p++) {
        if (p->active == 0) {
            b = (u8*)p;
            for (i = sizeof(Slot8002D0E4) - 1; i != -1; i--) {
                *b++ = 0;
            }
            return p;
        }
    }
    return 0;
}
