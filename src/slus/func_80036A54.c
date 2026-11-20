#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern s32 func_8003EF28(u8* arg0);
extern s32 func_80041DB0(u8* arg0);
extern s32 func_800437FC(u8* arg0);
extern s32 func_80041A54(u8* arg0);
extern void func_8003A874(u8* arg0);
extern s32 func_8004387C(u8* arg0);
extern s32 player_spawn_dash_spark(void* arg0);

void func_80036A54(u8* o) {
    if (func_8003EF28(o) != 0) {
        return;
    }
    if (func_80041DB0(o) != 0) {
        return;
    }
    if (func_800437FC(o) != 0) {
        return;
    }
    if (func_80041A54(o) != 0) {
        return;
    }
    if (*(u16*)(o + 0x80) & 0x80) {
        func_8003A874(o);
        return;
    }
    if (func_8004387C(o) != 0) {
        return;
    }
    if (o[0x45] & 0x20) {
        o[0x45] &= 0xF;
        player_spawn_dash_spark(o);
    }
    if (((s8*)o)[0x45] & 0x80) {
        o[0x45] &= 0xF;
        play_sound(1, 5, o);
        o[0x8C] = 1;
        o[6]++;
    } else {
        func_8003F2D8(o, 0x10);
    }
}
