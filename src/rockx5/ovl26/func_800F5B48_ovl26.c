#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F5B48_ovl26(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s16*)(obj + 0xA) < 0x990) {
        D_1F80004C.bytes[0x96] = 1;
        if (*(s16*)(obj + 0xA) < 0x910) {
            *(s16*)(obj + 0xA) += 1;
        } else if (*(s16*)(obj + 0xA) > 0x910) {
            *(s16*)(obj + 0xA) -= 1;
        }
    } else {
        D_1F80004C.bytes[0x96] = 0;
        if (*(s16*)(obj + 0xA) < 0xA10) {
            *(s16*)(obj + 0xA) += 1;
        } else if (*(s16*)(obj + 0xA) > 0xA10) {
            *(s16*)(obj + 0xA) -= 1;
        }
    }
    if (*(s16*)(obj + 0xE) < 0x123D) {
        *(s32*)(obj + 0x68) = 0;
        set_animation(obj, 0x16);
        obj[6]++;
    }
}
