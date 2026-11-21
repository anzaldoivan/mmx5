#include "types.h"
#include "mmx5/sound.h"

void func_800F4C20_ovl11(u8* p) {
    if (p[0x84] == 0) {
        if ((--p[0x83] & 1) == 0) {
            (*(s16*)(p + 0xE))++;
            if (((volatile u8*)p)[0x83] ==
                0) { // !FAKE: volatile forces the lbu 0x83 reload
                p[6] = p[0x87];
                play_sound(5, 0x1D, p);
            }
        } else {
            (*(s16*)(p + 0xE))--;
        }
    } else {
        p[0x84]--;
    }
    if (p[0x84] == 1) {
        play_sound(5, 0x1A, p);
    }
}

extern s8 D_800D1C26;

void func_800F4CD4_ovl11(u8* p) {
    if (D_800D1C26 == 1) {
        p[0x87] = 3;
        p[0x84] = 0x78;
        p[0x83] = 0x1E;
        p[0x6] = 0;
    }
}

extern s8 D_800D1C26;

void func_800F4D0C_ovl11(u8* p) {
    if (D_800D1C26 == 2) {
        p[0x87] = 5;
        p[0x84] = 0x78;
        p[0x83] = 0x1E;
        p[0x6] = 0;
    }
}
