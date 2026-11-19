#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800EFA5C_ovl18(u8* obj) {
    u8* parent;

    animate_object(obj);
    parent = *(u8**)(obj + 0x50);
    if (((s8*)parent)[6] >= 2) {
        if (((s8*)obj)[2] == 0) {
            if (((s8*)parent)[2] == 10) {
                set_animation(obj, 10);
            } else {
                set_animation(obj, 5);
            }
            obj[5]++;
        } else {
            obj[4]++;
        }
    }
}
