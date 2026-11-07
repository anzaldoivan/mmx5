#include "types.h"

extern void func_8003D0A0(u8* obj);
extern X4_BackgroundObj D_8009A1F8[3];

void func_80039F1C(u8* obj) {
    s16 d;
    s32 go;
    u16 t;

    go = 0;
    d = (*(u16*)(obj + 0xA) - 0x40) -
        (u16)D_8009A1F8[*(s8*)(obj + 0x14)].x_pos.i.hi;
    if (d != 0) {
        if (d > 0) {
            obj[0x15] = 0;
            go = d < 3;
        } else {
            obj[0x15] = 0x40;
            if (d >= -2) {
                goto one; // !FAKE: goto kept for the matching branch layout
            }
        }
    } else {
    one: // !FAKE: goto kept for the matching branch layout
        go = 1;
    }
    if (go != 0) {
        func_8003D0A0(obj);
        t = D_8009A1F8[*(s8*)(obj + 0x14)].x_pos.i.hi;
        *(s8*)(obj + 0xD0) = -1;
        obj[0x15] = 0x40;
        obj[5] = 0x14;
        *(u16*)(obj + 0xA) = t + 0x40;
    }
}
