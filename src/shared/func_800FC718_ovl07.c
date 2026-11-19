/* Shared body (DK-5), from the banked draft of func_800FC718_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void DEDUP_NAME(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        switch (D_1F80004C.bytes[0x90]) {
        case 0:
            set_animation(obj, 0x15);
            break;
        case 1:
            set_animation(obj, 0x15);
            break;
        case 2:
            set_animation(obj, 0x13);
            break;
        }
        obj[6]++;
    } else {
        animate_object(obj);
    }
}
