#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/object.h"

extern u8 D_800D1C00[];

void func_800F1F64_ovl08(u8* a0) {
    *(s32*)(a0 + 0x20) = 0;
    *(s32*)(a0 + 0x24) = 0xC000;
    a0[0x84] = 0;
    if (((s8*)a0)[3] != 0) {
        D_800D1C00[0x27]++;
        play_sound(5, 0x17, 0);
        a0[0x84] = 1;
    }
    a0[6]++;
}

extern u8 D_800D1C00[];

void func_800F1FD4_ovl08(u8* a0) {
    move_object(a0);
    if (*(s16*)(a0 + 0xE) <= *(s16*)(a0 + 0x7E)) {
        if (a0[0x84] != 0) {
            u8* p = D_800D1C00;
            p[0x27] = p[0x27] - 1;
            if (((s8*)p)[0x27] == 0) {
                play_sound(5, 0x14, 0);
            }
        }
        *(s16*)(a0 + 0x7C) = 0x78;
        a0[5] = 0;
        a0[6] = 0;
        *(s16*)(a0 + 0xE) = *(s16*)(a0 + 0x7E);
    }
}
