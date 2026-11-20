#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern u8 D_800755C0[];

void func_800FE720_ovl04(u8* p) {
    if (*(s8*)(p + 0x5C) < D_800D1CA2) {
        if (--*(s16*)(p + 0x7C) == 0) {
            play_sound(0, 0xE, 0);
            *(s16*)(p + 0x7C) = 2;
        }
        p[0x5C]++;
    } else {
        func_8003D2C4();
        *(u8**)(p + 0x58) = D_800755C0;
        p[5]++;
        p[0x8F] = 0;
        if (*(s8*)(p + 2) == 1) {
            p[0x8D] = 0x78;
        } else if (*(s8*)(p + 2) == 9) {
            p[0x8D] = 0x3C;
        } else {
            p[0x8D] = 0x3C;
        }
    }
}
