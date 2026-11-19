#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_8007B478[];
extern u8 D_80076F94[];

void func_80046AA8(u8* o) {
    u8* g = g_Player;
    u8* sp;
    s32 off;

    if ((s8)g[5] != 0x2C) {
        o[4] = 2;
        return;
    }
    if ((s8)g[0x45] & 0x80) {
        o[3] = 1;
        sp = D_1F80001C.bytes;
        off = *(s32*)(sp + 0x68);
        *(u8**)(o + 0x30) = D_8007B478;
        *(s16*)(o + 0x40) = 0x540;
        *(s16*)(o + 0x42) = 0x7801;
        o[0x16] = 0;
        o[0x15] = 0;
        *(u8**)(o + 0x3C) = sp + off;
        if (((s8*)o)[2] == 0) {
            *(u8**)(o + 0x50) = D_80076F94;
            o[0x64] = 1;
        }
        *(u16*)(o + 0xA) = *(u16*)(g + 0xA);
        *(u16*)(o + 0xE) = *(u16*)(g + 0xE);
        set_animation(o, (s8)o[2]);
        play_sound(1, 0x1A, o);
        *(s16*)(o + 0x8C) = 0;
        o[4]++;
    }
}
