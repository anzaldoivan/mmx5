#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F8978_ovl28(u8* obj) {
    u8* p = g_Player;
    s32 dx;
    s32 dy;

    dx = (*(s16*)(p + 0xA) - *(s16*)(obj + 0xA)) < 0
             ? (*(s16*)(obj + 0xA) - *(s16*)(p + 0xA))
             : (*(s16*)(p + 0xA) - *(s16*)(obj + 0xA));
    dy = *(s16*)(p + 0xE) - *(s16*)(obj + 0xE);
    if (dy >= 0 ? dx + dy < 6
                : dx + (*(s16*)(obj + 0xE) - *(s16*)(p + 0xE)) < 6) {
        obj[4] = 2;
    }
    func_8002D9EC(obj, 0x20, 0x20);
    animate_object(obj);
    move_object(obj);
}
