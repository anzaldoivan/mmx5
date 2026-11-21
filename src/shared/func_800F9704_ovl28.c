#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800F9704_ovl28(u8* self) {
    u8* s;

    if (*(signed char*)(self + 0x45) == 1) {
        self[0x45] = 0;
        play_sound(2, 0x8F, self);
        s = func_8002D1A4();
        if (s != 0) {
            s[0] = 0x41;
            s[1] = 0x24;
            s[2] = 4;
            *(u8**)(s + 0x7C) = self;
        }
    }
    if (*(signed char*)(self + 0x46) == 0) {
        set_animation(self, 2);
        self[5] = 3;
        self[6] = 0;
    }
}
