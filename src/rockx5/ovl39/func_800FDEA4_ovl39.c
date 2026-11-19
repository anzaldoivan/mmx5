#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void (*D_800FED3C_ovl39[])(u8*);

void func_800FDEA4_ovl39(u8* a0) {
    s8 s;

    *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
    *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
    D_800FED3C_ovl39[((s8*)a0)[4]](a0);
    if (((s8*)a0)[3]) {
        func_8002FB58(a0);
    }
    s = (*(s8**)(a0 + 0x7C))[4];
    if (s == 2) {
        if (((s8*)a0)[2] == 1) {
            play_sound(2, 0x6C, a0);
        }
        a0[4] = s;
    }
}
