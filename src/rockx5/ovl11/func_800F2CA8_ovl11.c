#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F2CA8_ovl11(u8* obj) {
    animate_object(obj);
    if (++D_1F80004C.bytes[0x81] == 60) {
        set_animation(obj, 1);
        obj[5] = 2;
        obj[6] = 0;
    }
}
