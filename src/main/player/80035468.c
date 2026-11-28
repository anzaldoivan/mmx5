#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80035144.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003A670(void* arg0);
M2C_UNK func_8003CD08();
void func_8003D344(void* arg0);
M2C_UNK func_8003B65C(void*);
M2C_UNK func_8003D5E0(void*);
extern s8 D_800D1C1C;

void update_stage_entry(void* arg0) {
    X4_BackgroundObj* bg;

    ((void (*)())animate_object)();
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        if (M2C_FIELD(arg0, s8*, 0xCE) != 0) {
            if (--M2C_FIELD(arg0, s8*, 0xCE) == 0) {
                func_8003CD08(arg0);
            }
            move_object(arg0);
            return;
        }
        if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
            func_8003B33C(arg0, 2);
            M2C_FIELD(arg0, s8*, 0x67) = 0;
            bg = D_8009A1F8.bg;
            M2C_FIELD(&bg[0], s8*, 0x44) = 1;
            M2C_FIELD(&bg[1], s8*, 0x44) = 1;
            M2C_FIELD(&bg[2], s8*, 0x44) = 1;
            M2C_FIELD(arg0, s8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
            return;
        }
        move_object(arg0);
        func_8003D344(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        func_8003D5E0(arg0);
        func_8003B65C(arg0);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        D_800D1C1C = 0;
        if (M2C_FIELD(arg0, s8*, 2) != 0) {
            func_8003D5E0(arg0);
            func_8003B65C(arg0);
        }
        func_8003A670(arg0);
    }
}
#undef M2C_UNK
#undef M2C_FIELD

extern s32 func_8003EFE0(u8* arg0);
extern s32 func_80043904(u8* arg0);
extern s32 try_grab_ladder_from_air(u8* obj);
extern s32 func_800390A4(u8* p);
extern s32 try_enter_wall_cling(void* self);
extern s32 func_80038850(u8* self);
extern void func_8003D120(u8*);
extern void func_8003D344(void* arg0);
extern void player_set_animation_shooting(u8* arg0, s32 arg1);

void func_80035598(u8* arg0) {
    func_80043B88(arg0);
    if (((s8*)arg0)[0xD3] != 0) {
        *(s32*)(arg0 + 0x24) = 0;
    }
    if (arg0[0x89] & 4) {
        *(s32*)(arg0 + 0x24) = 0;
    }
    if (!(*(u16*)(arg0 + 0x7C) & 0x80)) {
        *(s32*)(arg0 + 0x24) = 0;
    }
    if (func_8003EFE0(arg0) != 0) {
        return;
    }
    if (func_80043904(arg0) != 0) {
        return;
    }
    animate_object(arg0);
    if (((s8*)arg0)[0x45] & 0x80) {
        arg0[0x45] &= 0x3F;
        play_sound(1, 1, arg0);
    }
    if (try_grab_ladder_from_air(arg0) != 0) {
        return;
    }
    if (func_800390A4(arg0) != 0) {
        return;
    }
    if (((s8*)arg0)[0x8B] == 0) {
        if (try_enter_wall_cling(arg0) != 0) {
            return;
        }
    } else {
        arg0[0x8B]--;
    }
    if (func_80038850(arg0) != 0) {
        return;
    }
    func_8003D120(arg0);
    func_8003D344(arg0);
    if (*(s32*)(arg0 + 0x24) <= 0) {
        player_set_animation_shooting(arg0, 0xB);
        ((s8*)arg0)[0x67] = -1;
        arg0[5] = 7;
        arg0[6] = 0;
        return;
    }
    player_update_animation_shooting(arg0, 0xA);
}
