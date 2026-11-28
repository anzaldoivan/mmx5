#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern int func_80045D44();
extern void load_buffered_palette(s32 arg0, s32 arg1, s32 arg2);
extern u8 D_8007B468[];
extern u8 D_80077190[];
extern u8 D_80077194[];

void func_8004A214(u8* arg0) {
    u8* base;
    u8* p;
    u8 t;

    base = g_Player;
    arg0[3] = 1;
    *(u8**)(arg0 + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x20);
    *(u8**)(arg0 + 0x3C) = D_1F80001C.bytes + *(s32*)(D_1F80001C.bytes + 0x40);
    *(u8**)(arg0 + 0x30) = D_8007B468;
    *(s16*)(arg0 + 0x40) = 0x520;
    *(s16*)(arg0 + 0x42) = 0x7801;
    arg0[0x16] = 1;
    t = base[0x15];
    arg0[0x15] = t;
    *(u8**)(arg0 + 0x50) = D_80077190;
    *(u8**)(arg0 + 0x68) = D_80077194;
    *(s8*)(arg0 + 0x14) = -1;
    func_80045D44(arg0, base, ((s8*)arg0)[1], t);
    p = D_8009A1F8.u;
    *(s16*)(arg0 + 0xA) -= *(s16*)(p + 0xA);
    *(s16*)(arg0 + 0xE) -= *(s16*)(p + 0xE);
    if (base[0x15] != 0) {
        *(s32*)(arg0 + 0x20) = 0x5A820;
    } else {
        *(s32*)(arg0 + 0x20) = -0x5A820;
    }
    *(s32*)(arg0 + 0x24) = 0x5A820;
    set_animation(arg0, 0);
    play_sound(1, 0x16, arg0);
    *(s16*)(arg0 + 0x8E) = 0;
    arg0[4]++;
    load_buffered_palette(0x1E, 1, 1);
}
