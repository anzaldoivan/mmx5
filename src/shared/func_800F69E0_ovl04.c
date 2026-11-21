#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800F69E0_ovl04(u8* arg0) {
    u8* src = *(u8**)(arg0 + 0x7C);

    *(u16*)(arg0 + 0xA) = *(u16*)(src + 0xA);
    *(u16*)(arg0 + 0xE) = *(u16*)(src + 0xE);
}

void func_800F6A00_ovl04(u8* obj) {
    animate_object(obj);
    *(s32*)(obj + 0x20) = 0xFFFF0000;
    obj[6] = 1;
}

void func_800F6A34_ovl04(u8* obj) {
    u8* plr;
    s32 target;

    animate_object(obj);
    plr = g_Player;
    if (*(s16*)(plr + 0xA) < *(s16*)(obj + 0xA)) {
        target = *(s16*)(plr + 0xE) - 8;
        if (*(s16*)(obj + 0xE) < target) {
            *(s16*)(obj + 0xE) += 1;
        } else if (target < *(s16*)(obj + 0xE)) {
            *(s16*)(obj + 0xE) -= 1;
        }
    }
    move_object(obj);
}
