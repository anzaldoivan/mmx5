#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800FBB58_ovl38(u8* obj) {
    animate_object(obj);
    if (*(s16*)(obj + 0x7C) != 0) {
        *(s16*)(obj + 0x7C) -= 1;
    } else {
        apply_object_motion(obj);
    }
    ((s32(*)())func_8002FB58)(obj);
    if (obj[0x70] & 8) {
        obj[6]++;
    }
}
