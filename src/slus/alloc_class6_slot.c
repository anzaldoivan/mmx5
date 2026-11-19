#include "types.h"
#include "mmx5/object.h"

extern Slot8002D27C D_8009F9A0[64];

Slot8002D27C* alloc_class6_slot(void) {
    Slot8002D27C* p;
    u8* b;
    s32 i;

    for (p = D_8009F9A0; p < &D_8009F9A0[64]; p++) {
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
