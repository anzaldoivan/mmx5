#include "types.h"
#include "mmx5/globals.h"

void func_800FB9E8_ovl39(u8* obj) {
    u8* p;
    u8* q;
    s32 d;

    animate_object(obj);
    func_800317B8(obj);
    if (--*(u16*)(obj + 0x8C) != 0) {
        return;
    }
    if (*(s8*)(obj + 2) == 10) {
        p = g_Player;
        d = *(s16*)(p + 0xA) - *(s16*)(obj + 0xA);
        if ((d >= 0) ? (d >= 0x30)
                     : (*(s16*)(obj + 0xA) - *(s16*)(p + 0xA) >= 0x30)) {
            q = g_Player;
            if (*(s16*)(q + 0xA) > *(s16*)(obj + 0xA)) {
                *(s32*)(obj + 0x28) = -0x2800;
            } else {
                *(s32*)(obj + 0x28) = 0x2800;
            }
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x24) = 0;
            *(s32*)(obj + 0x2C) = 0;
        } else {
            if (*(s16*)(obj + 0xE) >= 0x821) {
                *(s32*)(obj + 0x2C) = -0x2800;
            } else {
                *(s32*)(obj + 0x2C) = 0x2800;
            }
            *(s32*)(obj + 0x24) = 0;
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
        }
        *(u16*)(obj + 0x8C) = 0;
        obj[0x8E] = 0;
        obj[5]++;
    } else {
        obj[4] = 2;
    }
}
