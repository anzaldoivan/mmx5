#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_800F0DD0_ovl07(u8* arg0) {
    if (*(s16*)(arg0 + 0xA) >= 0x1EFB) {
        play_sound(5, 0x14, 0);
        arg0[5]++;
        *(s16*)(arg0 + 0x9C) = 0;
        func_8002C218();
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_80093E68 = 0x7C00;
    } else {
        move_object(arg0);
    }
}
