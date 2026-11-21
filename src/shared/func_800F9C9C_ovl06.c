#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F9C9C_ovl06(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    ((s32(*)())func_8002FB58)(obj);
    if (*(s32*)(obj + 0x24) < 0) {
        set_animation(obj, 0x14);
        obj[6]++;
    }
}
