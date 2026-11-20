#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_8004C99C(u8* obj) {
    u8* g = g_Player;
    s32 mask;
    s16 d;

    animate_object(obj);
    apply_object_motion(obj);
    mask = 1;
    if (obj[0x15] == 0) {
        mask = 2;
    }
    if (*(s16*)(g + 0xA) - *(s16*)(obj + 0xA) >= 0) {
        d = *(u16*)(g + 0xA) - *(u16*)(obj + 0xA);
    } else {
        d = *(u16*)(obj + 0xA) - *(u16*)(g + 0xA);
    }
    if (*(s8*)(g + 5) != 0x3B || (obj[0x70] & mask) || d >= 0x61) {
        func_8003B33C(obj, 0x11);
        obj[5] = 1;
        *(s16*)(obj + 0x88) = 0;
        return;
    }
    if (*(s8*)(obj + 3) == 0) {
        obj[4]++;
        return;
    }
    if (*(s8*)(obj + 0x98) != 0) {
        *(s32*)(obj + 0x50) = 0;
        func_8003B33C(obj, 0x68);
        obj[5] = 2;
    }
    func_8002D89C(obj);
}
