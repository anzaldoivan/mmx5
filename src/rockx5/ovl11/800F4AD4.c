#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

void func_800F4AD4_ovl11(u8* arg0) {
    u8* p;

    if (D_8009A0AA >= 0x849) {
        ((s32(*)())func_8003D29C)(0x14, 0x40);
        p = D_8009A1F8.u;
        *(s16*)(p + 0x26) = 0x780;
        *(s16*)(p + 0x28) = 0x780;
        *(s16*)(p + 0x2A) += 0x2B;
        arg0[6] = 1;
    }
}

extern void start_pad_vibration(s32);

void func_800F4B38_ovl11(u8* a0) {
    u8* p = D_8009A1F8.u;

    if (*(s16*)(p + 0xE) == 0x2FB) {
        *(s16*)(p + 0x2E) = 0x80;
        a0[0x83] = 0x1E;
        start_pad_vibration(6);
        play_sound(5, 0x1A, a0);
        a0[6] = 2;
    }
}

void func_800F4B9C_ovl11(u8* p) {
    p[0x83]--;
    if ((p[0x83] & 1) == 0) {
        (*(s16*)(p + 0xE))++;
        if (((volatile u8*)p)[0x83] == 0) { // !FAKE: volatile forces the reload
            play_sound(5, 0x1D, p);
            p[6] = 3;
            func_8003D2C4();
        }
    } else {
        (*(s16*)(p + 0xE))--;
    }
}
