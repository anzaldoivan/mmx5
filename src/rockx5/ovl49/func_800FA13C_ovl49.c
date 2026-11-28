#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"

extern u8 D_80091C44;

void func_800FA13C_ovl49(u8* arg0) {
    u8* p;

    if (++*(u16*)(arg0 + 4) & 1) {
        p = D_8009A1F8.u;
        *(s16*)(p + 0xA) = 0x2C0 - random_byte() % 5;
        *(s16*)(p + 0xE) = 0x38 - random_byte() % 3;
    } else {
        u8* r = D_8009A1F8.u;
        *(s16*)(r + 0xA) = 0x2C0;
        *(s16*)(r + 0xE) = 0x38;
    }
    if (D_80091C44 == 0) {
        u8* q = D_8009A1F8.u;
        s32 one = 1;
        q[3] = 0;
        q[0x57] = 0;
        *(s32*)(q + 0xB0) = 0;
        *(s32*)(q + 0xB4) = 0x02000000;
        q[0xAB] = one;
        q[0xF4] = one;
        play_sound(2, 0x6C, 0, one);
        func_8002385C(0x2E, 0xFF, 0);
        arg0[1]++;
    }
}
