#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F89EC_ovl00(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        if (*(s16*)(obj + 0xA) - D_8009A0AA < 0) {
            set_animation(obj, 3);
            obj[6] += 3;
        } else {
            *(s16*)(obj + 0x7C) = 10;
            obj[6]++;
        }
    }
    animate_object(obj);
    apply_object_motion(obj);
}
