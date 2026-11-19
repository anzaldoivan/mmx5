/* Shared body (DK-5), from the banked draft of func_800F5C64_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

extern u8* alloc_class3_slot(void);

void DEDUP_NAME(u8* obj) {
    u8* p;

    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[5]++;
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x1A;
            *(s16*)(p + 0xA) = *(s16*)(obj + 0xA);
            *(s16*)(p + 0xE) = *(s16*)(obj + 0xE);
            *(u8**)(obj + 0x80) = p;
        }
    }
    ((s32(*)())func_8002D89C)(obj);
    if (--*(s16*)(obj + 0x7E) == -1) {
        *(u16*)(obj + 0x42) ^= 0x8000;
        *(s8*)(obj + 0x89) -= 5;
        *(s16*)(obj + 0x7E) = (*(s8*)(obj + 0x89) < 6) ? 5 : *(s8*)(obj + 0x89);
    }
}
