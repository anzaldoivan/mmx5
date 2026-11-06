#include "types.h"

extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);

void func_800F2C18_ovl07(u8* o) {
    u16 t;

    func_8002DF54(o);
    func_80017248(o);
    if (((s8*)o)[2] != 0) {
        *(s32*)(o + 0x24) = -*(s32*)(o + 0x24);
    } else {
        *(s32*)(o + 0x20) = -*(s32*)(o + 0x20);
    }
    t = *(u16*)(o + 0x88);
    if (t == 0) {
        if (((s8*)o)[2] != 0) {
            *(s32*)(o + 0x24) = -0x80000;
            *(s32*)(o + 0x20) = 0;
            o[0x47] = 0x5E;
            *(u16*)(o + 0xE) = *(u16*)(o + 0x8A);
        } else {
            if (o[0x86] != 0) {
                *(s32*)(o + 0x20) = -0x80000;
            } else {
                *(s32*)(o + 0x20) = 0x80000;
            }
            *(s32*)(o + 0x24) = 0;
            o[0x47] = 0x10;
            *(u16*)(o + 0xA) = *(u16*)(o + 0x8A);
        }
        o[6]++;
        return;
    }
    *(u16*)(o + 0x88) = t - 1;
}
