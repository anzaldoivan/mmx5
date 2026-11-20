#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F889C_ovl00(u8* obj) {
    set_animation(obj, 2);
    obj[6]++;
    animate_object(obj);
    apply_object_motion(obj);
}
