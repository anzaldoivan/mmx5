#include "types.h"
#include "mmx5/object.h"

Slot8002D0E4* find_free_visual_obj(void) {
    Slot8002D0E4* p;
    u8* b;
    s32 i;

    for (p = D_80094398.d0e4; p < &D_80094398.d0e4[96]; p++) {
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
