#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void player_clear_dash(u8*);
extern void func_8003CF74(u8*, s32);
extern void func_80043E78(u8*);

s32 func_80044228(u8* arg0) {
    if (!(arg0[0xC9] & 0x10) || !(*(u16*)(arg0 + 0x7C) & 4) ||
        !(*(u16*)(arg0 + 0x80) & 0x10)) {
        return 0;
    }
    if (*(s8*)(arg0 + 0x8E) != 0) {
        return 0;
    }
    arg0[0x156] = 1;
    arg0[0x8E] = 1;
    arg0[0xCB] = 0;
    arg0[0x8C] = 0;
    player_clear_dash(arg0);
    func_8003B33C(arg0, 0x65);
    func_8003CF74(arg0, 9);
    play_sound(1, 0x10, arg0);
    arg0[5] = 0x39;
    arg0[0x67] = 1;
    arg0[0x7A] = 1;
    arg0[6] = 0;
    *(s8*)(arg0 + 0x4B) = -1;
    arg0[0x4C] = 4;
    arg0[0x4D] = 0xA;
    arg0[0x4E] = 2;
    arg0[0x4F] = 0;
    func_80043E78(arg0);
    return 1;
}
