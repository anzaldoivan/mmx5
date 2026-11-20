#include "types.h"
#include "mmx5/globals.h"

extern void start_pad_vibration(s32);
extern s32 func_8003D010(s8 dmg);
extern s32 func_8002E198(s32);

void func_800F2324_ovl10(u8* obj) {
    s16 old;
    s32 m;

    animate_object(obj);
    if (--*(s16*)(obj + 0x92) == 0) {
        start_pad_vibration(8);
        func_8003D010(1);
        *(s16*)(obj + 0x92) = 0x3C;
    }
    old = *(s16*)(obj + 0x90);
    m = g_Player[0x5C] & 0x7F;
    if (m != 0) {
        *(u16*)(obj + 0x90) += func_8002E198(m);
    }
    if (old != *(s16*)(obj + 0x90)) {
        *(u16*)(obj + 0x42) |= 0x8000;
    } else {
        *(u16*)(obj + 0x42) &= 0x7FFF;
    }
    if ((*(s16*)(obj + 0x90) >= 0x20 || (s8)g_Player[0xCA] == 0) &&
        (g_Player[0x5C] & 0x7F)) {
        obj[0x62] = 0;
        *(u16*)(obj + 0x42) &= 0x7FFF;
        g_Player[0xCA] = 0;
        obj[4] = 4;
        obj[5] = 0;
    }
}
