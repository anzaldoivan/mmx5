#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F8934_ovl00(u8* obj) {
    u8* p = g_Player;
    s32 y;

    if (*(s16*)(obj + 0xA) - *(s16*)(p + 0xA) < 0x50) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s16*)(obj + 0x7C) = 50;
        obj[6]++;
    }
    if (*(s32*)(obj + 0x20) > 0x3FFFF) {
        *(s32*)(obj + 0x28) = 0;
    }
    y = *(s16*)(obj + 0xE) + 0x30;
    if (y < *(s16*)(p + 0xE)) {
        *(s16*)(obj + 0xE) += 1;
    } else if (*(s16*)(p + 0xE) < y) {
        *(s16*)(obj + 0xE) -= 1;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
