#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/weapon.h"
#include "mmx5/sound.h"
#include "mmx5/object.h"

/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EC4C0.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK player_nova_strike_hit_wall();

void player_nova_strike_windup(void* arg0) {
    player_nova_strike_hit_wall();
    if (M2C_FIELD(arg0, s8*, 0x45) & 0x80) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        return;
    }
    apply_object_motion(arg0);
}
#undef M2C_UNK
#undef M2C_FIELD

extern s32 player_nova_strike_hit_wall(u8* obj);
extern void func_8003AA4C(u8* arg0);
extern void func_8003CEDC(u8* arg0, s32 arg1);
extern s8 D_800D1C1C;

void func_80040D24(u8* obj) {
    if (player_nova_strike_hit_wall(obj) != 0 && (obj[0x45] & 0x40)) {
        if (*(s8*)(obj + 0xD3) == 0) {
            obj[0x7A] = 0;
        }
        obj[0xF3] = 0;
        D_800D1C1C = 0;
        func_8003AA4C(obj);
        return;
    }
    if (obj[0x45] & 0x20) {
        obj[0x45] = 0;
        player_spawn_weapon(1, 0x16, 0, 0);
        func_8003CEDC(obj, 0x49);
        play_sound(1, 5, obj);
        play_sound(0, 0x20, obj);
        if (obj[0x15] != 0) {
            *(s32*)(obj + 0x20) = 0x80000;
        } else {
            *(s32*)(obj + 0x20) = 0xFFF80000;
        }
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6]++;
    }
}

extern s32 player_nova_strike_hit_wall(u8* obj);
extern void func_8003C5D8(u8* obj);
extern void func_8003AA4C(u8* arg0);
extern s8 D_800D1C1C;

void func_80040E14(u8* obj) {
    s32 f;
    u8 t;

    f = player_nova_strike_hit_wall(obj) != 0;
    t = obj[0xF4];
    if (t == 0) {
        f = 1;
    }
    if (f) {
        if (*(s8*)(obj + 0xD3) == 0) {
            obj[0x7A] = 0;
        }
        obj[0xF3] = 0;
        D_800D1C1C = 0;
        func_8003C5D8(obj);
        func_8003AA4C(obj);
    } else {
        obj[0xF4] = t - 1;
        move_object(obj);
    }
}
