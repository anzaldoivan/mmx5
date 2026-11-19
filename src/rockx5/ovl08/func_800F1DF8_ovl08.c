#include "types.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"

extern void start_pad_vibration(s32);

void func_800F1DF8_ovl08(u8* a0) {
    move_object(a0);
    if (*(s16*)(a0 + 0xE) >= *(s16*)(a0 + 0x7E) + *(s16*)(a0 + 0x80)) {
        if (((s8*)a0)[3] != 0) {
            start_pad_vibration(5);
            play_sound(5, 0x15, a0);
        }
        *(s16*)(a0 + 0x7C) = 0x78;
        *(s16*)(a0 + 0xE) = *(s16*)(a0 + 0x7E) + *(s16*)(a0 + 0x80);
        a0[6]++;
    }
}
