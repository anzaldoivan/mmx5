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

void update_dash_start(u8* o) {
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
        player_update_animation_shooting(o, 0x10);
    }
}

extern void func_8003CD08(u8* obj);
extern s32 func_8003EF28(u8* arg0);
extern s32 func_80041DB0(u8* obj);
extern s32 func_800437FC(u8* arg0);
extern s32 func_80041A54(u8* arg0);
extern void func_8003A874(u8*);
extern s32 func_8004387C(u8* arg0);
extern s32 func_800398E8(u8* obj);
extern void func_8003AB50(u8* arg0);
extern void func_8003D200(u8* obj);
extern void func_8003C8B8(void* arg0);
extern void func_8003CD60(u8* obj);

void func_80036B50(u8* obj) {
    u8 v;

    func_8003CD08(obj);
    if (func_8003EF28(obj) != 0) {
        return;
    }
    if (func_80041DB0(obj) != 0) {
        return;
    }
    if (func_800437FC(obj) != 0) {
        return;
    }
    if (func_80041A54(obj) != 0) {
        return;
    }
    if (*(u16*)(obj + 0x80) & 0x80) {
        func_8003A874(obj);
        return;
    }
    if (func_8004387C(obj) != 0) {
        return;
    }
    if (func_800398E8(obj) != 0) {
        func_8003AB50(obj);
        return;
    }
    v = obj[0x45];
    if (v & 0x40) {
        obj[0x45] = v & 0xF;
        func_8003D200(obj);
    }
    if (!(obj[0x85] & 3)) {
        func_8003C8B8(obj);
    }
    player_update_animation_shooting(obj, 0x10);
    func_8003CD60(obj);
}
