#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void silence_sound(s32, s32);
extern void func_8002A600(s32, s32, s32);
extern u8 D_8009A1F8[];

void func_800F3B04_ovl11(u8* arg0) {
    u8* g = g_Player;

    if (((s8*)g)[0xF3] == 0) {
        if (!(++arg0[0x85] & 1)) {
            u8* p = D_8009A1F8;
            *(u16*)(p + 0x28) -= 1;
            *(u16*)(p + 0x2A) -= 1;
        }
        move_object(arg0);
    } else if ((u8)(g[0xFA] - 2) >= 2) {
        if (!(++arg0[0x85] & 1)) {
            u8* q = D_8009A1F8;
            *(u16*)(q + 0x28) -= 1;
            *(u16*)(q + 0x2A) -= 1;
        }
        move_object(arg0);
    }
    if (*(s16*)(arg0 + 0xE) == 0x490) {
        u8* r;
        arg0[6]++;
        r = D_8009A1F8;
        if (*(s16*)(r + 0x2A) == *(s16*)(r + 0x28)) {
            silence_sound(5, 0x1D);
            play_sound(5, 0x1B, arg0);
            func_8002A600(0x20, 2, 1);
        }
    }
}
