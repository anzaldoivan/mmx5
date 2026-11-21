#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u16 D_800F2100_ovl12;

void func_800F0E00_ovl12(u8* obj) {
    u8* d;
    u8* d2;
    s32 t;
    u16 e;

    if (((s8*)*(u8**)(obj + 0x80))[7] != 0) {
        d = g_Player;
        if (*(s16*)(d + 0xA) < *(s16*)(obj + 0xA)) {
            d[0x15] = 0x40;
        } else {
            d[0x15] = 0;
        }
        *(u16*)(obj + 0x42) &= 0x7FFF;
        d2 = g_Player;
        if (*(s16*)(d2 + 0xA) > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        set_animation(obj, 0xB);
        e = D_800F2100_ovl12;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x68) = 0;
        *(u16*)(obj + 0xE) = e;
        obj[5]++;
        return;
    }
    t = *(u16*)(obj + 0x7E) - 1;
    *(u16*)(obj + 0x7E) = t;
    if ((s16)t == -1) {
        *(u16*)(obj + 0x7E) = 5;
        *(u16*)(obj + 0x42) ^= 0x8000;
    }
    func_8002D9EC(obj, 0x40, 0x40);
}
