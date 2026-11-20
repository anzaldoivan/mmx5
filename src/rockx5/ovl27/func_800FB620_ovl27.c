#include "types.h"
#include "mmx5/object.h"

void func_800FB620_ovl27(u8* obj) {
    move_object(obj);
    if (--*(s16*)(obj + 0x88) == 0) {
        obj[4] += 1;
    }
}
