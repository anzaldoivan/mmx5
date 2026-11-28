#include "types.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern s32 func_80044328(u8*);
extern s32 func_800306E0(u8*);
extern s32 func_8003A134(u8*, s32);
extern void func_8003CF74(u8*, s32);
extern void player_clear_dash(u8*);
extern void func_800443A8(u8*, s8);
extern void func_8003A874(u8*);

s32 func_800418DC(u8* arg0) {
    if (func_80044328(arg0) == 0) {
        return 0;
    }
    func_8003B33C(arg0, func_8003A134(arg0, func_800306E0(arg0) & 0xFF) + 0x6B);
    play_sound(1, 8, arg0);
    if (random_byte() & 4) {
        func_8003CF74(arg0, 8);
    }
    player_clear_dash(arg0);
    arg0[5] = 0x3D;
    arg0[6] = 0;
    func_80043B88(arg0);
    if (*(s8*)(arg0 + 6) == 0) {
        arg0[6]++;
    } else {
        animate_object(arg0);
        func_800443A8(arg0, (arg0[0x45] & 0x7F) + 0x26);
    }
    if (*(u16*)(arg0 + 0x80) & 2) {
        arg0[0x15] = 0;
    }
    if (*(u16*)(arg0 + 0x80) & 1) {
        arg0[0x15] = 0x40;
    }
    if (*(s8*)(arg0 + 0xD3) == 0) {
        arg0[0x8E] = 0;
        if (*(u16*)(arg0 + 0x80) & 0x80) {
            func_8003A874(arg0);
            return 1;
        }
        arg0[0x8E] = 1;
    }
    if (*(s8*)(arg0 + 0x46) == 0) {
        arg0[0x8E] = 0;
        if (func_800306E0(arg0) == 0x2E) {
            arg0[5] = 0x1B;
        } else {
            arg0[5] = 0x1C;
        }
        arg0[6] = 1;
    }
    return 1;
}
