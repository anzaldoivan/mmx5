#include "types.h"
#include "mmx5/object.h"

Slot8002D144* alloc_class7_slot(void) {
    Slot8002D144* p;
    u8* b;
    s32 i;

    for (p = g_class7_slots.d144; p < &g_class7_slots.d144[4]; p++) {
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
