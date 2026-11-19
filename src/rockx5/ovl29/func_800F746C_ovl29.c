#include "types.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern s16 D_8009A206;

void func_800F746C_ovl29(u8* p) {
    s32 t;

    func_800317B8(p);
    move_object(p);
    animate_object(p);
    if (*(s16*)(p + 0xE) - D_8009A206 < 0x78) {
        *(s32*)(p + 0x24) = 0;
    }
    t = *(u16*)(p + 0x88) - 1;
    *(u16*)(p + 0x88) = t;
    if ((t << 16) == 0) {
        *(s32*)(p + 0x68) = 0;
        *(s32*)(p + 0x24) = 0xFFFC0000;
        p[6]++;
    }
    if (*(s8*)(p + 0x45) == 1) {
        play_sound(2, 0xAE, p);
    }
    if (*(s8*)(p + 0x45) == 2) {
        play_sound(2, 0xAE, p);
    }
    func_8002D9EC(p, 0x30, 0x80);
}
