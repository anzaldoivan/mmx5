#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern s16 D_8009A256;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern u8* alloc_class3_slot(void);

void func_800EF920_ovl01(u8* arg0) {
    u8* p;
    u8 t;

    if (D_8009A256 >= 0xFD0) {
        play_sound(0, 5, 0);
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 8;
        }
        ((s32(*)())func_8003D29C)(0x1E, 0x40);
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C218();
        t = arg0[5];
        arg0[0x19] = 4;
        arg0[0x1A] = 2;
        arg0[0x1B] = 0;
        arg0[5] = t + 1;
    }
}
