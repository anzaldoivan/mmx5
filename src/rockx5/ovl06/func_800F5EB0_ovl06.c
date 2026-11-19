#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FE920_ovl06[];

void func_800F5EB0_ovl06(u8* o) {
    u8 f70;
    u8 f8D;
    s32 t;

    if (*(s8*)(o + 6) == 0) {
        o[6] = 1;
        set_animation(o, 8);
        *(u8**)(o + 0x50) = D_800FE920_ovl06;
        o[0x60] = 6;
        o[0x8D] |= 8;
    }
    t = o[0x8E] - 1;
    f70 = o[0x70];
    o[0x8E] = t;
    if (!(f70 & 8)) {
        o[5] = 4;
        o[6] = 0;
        return;
    }
    f8D = o[0x8D];
    if (!(f8D & 2)) {
        if ((f70 & 3) || (o[0x45] & 1)) {
            if ((s8)t < 0) {
                o[5] = 7;
                o[6] = 0;
                o[0x8D] = f8D & 0xF7;
            } else {
                *(s32*)(o + 8) += *(s32*)(o + 0x20);
            }
        }
        animate_object(o);
        return;
    }
    animate_object(o);
}
