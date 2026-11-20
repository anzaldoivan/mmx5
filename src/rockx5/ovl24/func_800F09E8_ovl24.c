#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern u16 D_800C9320;

extern void func_800211C4(void*, s32);
extern void func_800132F8(s8 arg);

void func_800F09E8_ovl24(u8* arg0) {
    u8* p = D_8009A420;

    if (((signed char*)p)[4] == 0) {
        func_800211C4(p + 7, *(s16*)(arg0 + 8));
        if (D_800C9320 & 0x40) {
            play_sound(0, 0x22, 0);
            func_800132F8(8);
            arg0[2]++;
        }
    }
}
