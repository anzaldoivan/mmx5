#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F57A0_ovl26(u8* obj) {
    if (D_1F80004C.bytes[0x92] == 0) {
        animate_object(obj);
        if (--*(s16*)(obj + 0x7E) != 0) {
            obj[6] = 0;
        } else {
            obj[6]++;
            set_animation(obj, 0x14);
        }
    }
}
