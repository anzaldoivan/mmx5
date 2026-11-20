#include "types.h"
#include "mmx5/sound.h"
#include "addr.h"

extern void silence_sound(s32, s32);
extern void func_800F8ED0_ovl09(u8*, s32);
extern void func_800F8FE4_ovl09(u8*, s16, s16, u8);

void func_800F8BCC_ovl09(u8* p) {
    if (--*(s16*)(p + 0x7C) == 0) {
        if (D_1F80004C.bytes[0x84] == 2) {
            silence_sound(2, 0x26);
        }
        play_sound(2, 0x25, 0);
        func_800F8ED0_ovl09(p, 0);
        func_800F8ED0_ovl09(p, 1);
        func_800F8FE4_ovl09(p, *(s16*)(p + 0xA), *(s16*)(p + 0xE), 2);
        *(s16*)(p + 0x7C) = 0x84;
        p[6]++;
    }
}
