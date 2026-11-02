#include "types.h"

extern u8* func_8002D1A4();

void func_800FCCC0_ovl39(u8* o) {
    u8* c;

    if (--*(s16*)(o + 0x7C) == 0) {
        if (*(s16*)(o + 0x7E) != 5) {
            c = func_8002D1A4();
            if (c != 0) {
                c[0] = 0x61;
                c[1] = 0x28;
                c[2] = o[0x7E] + 6;
                *(u16*)(c + 0x40) = *(u16*)(o + 0x40);
                *(s32*)(c + 0x30) = *(s32*)(o + 0x30);
                *(s32*)(c + 0x3C) = *(s32*)(o + 0x3C);
                *(u16*)(c + 0x42) = *(u16*)(o + 0x42) & 0x7FFF;
                c[0x15] = o[0x15];
                *(u8**)(c + 0x7C) = o;
            }
            *(s16*)(o + 0x7C) = 0x28;
            *(s16*)(o + 0x7E) = *(s16*)(o + 0x7E) + 1;
            return;
        }
        o[6]++;
    }
}
