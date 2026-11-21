#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/player.h"

extern void* player_spawn_visual(s8 arg0, s8 arg1, s8 arg2, s32 arg3);

void func_800407CC(u8* arg0) {
    func_8003F2D8(arg0, 0x15);
    if (((s8*)arg0)[0x45] & 0x80) {
        arg0[0x45] &= 0x7F;
        player_spawn_visual(0x21, 0x21, 0, 0);
        arg0[6]++;
    }
}

extern s32 try_enter_wall_cling(void* self);
extern s32 func_8003979C(u8* self);
extern void func_8003ABD0(u8* self);
extern s32 func_80040BBC(void* self);

void func_80040830(u8* self) {
    s32 dir;

    if (func_80040B6C(self) != 0) {
        return;
    }
    if (try_enter_wall_cling(self) != 0) {
        return;
    }
    if (func_8003979C(self) != 0 && self[0x92] == 0) {
        func_8003ABD0(self);
        return;
    }
    dir = func_80040BBC(self);
    if (dir != 0) {
        self[0xE8] = 0x28;
        player_hover_set_direction(self, dir);
    } else {
        func_8003F2D8(self, 0x15);
    }
}

/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EC0C0.c, AGPL-3.0 (THIRD_PARTY.md). */

s32 try_enter_wall_cling(void*); /* extern */
s32 func_80040BBC(void*);        /* extern */

void player_hover_hold(s32 arg0) {
    s32 temp_v0;

    if ((func_80040B6C() == 0) && (try_enter_wall_cling(arg0) == 0)) {
        temp_v0 = func_80040BBC(arg0);
        if (temp_v0 != 0) {
            player_hover_set_direction(arg0, temp_v0);
            return;
        }
        func_8003F2D8(arg0, 0x16);
    }
}

/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EC124.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 try_enter_wall_cling(void*);                       /* extern */
M2C_UNK player_set_animation_shooting(void*, M2C_UNK); /* extern */
s32 func_80040BBC(void*);                              /* extern */

void player_hover_forward(void* arg0) {
    s32 temp_v0;
    s8 var_v0;

    if ((func_80040B6C() == 0) && (try_enter_wall_cling(arg0) == 0)) {
        temp_v0 = func_80040BBC(arg0);
        if (temp_v0 != 0) {
            if (temp_v0 > 0) {
                move_object(arg0);
                func_8003F2D8(arg0, 0x17);
                return;
            }
            player_set_animation_shooting(arg0, 0x19);
            var_v0 = 5;
            goto block_7; // !FAKE: shared tail store; if/else orders blocks differently
        }
        player_set_animation_shooting(arg0, 0x18);
        var_v0 = 4;
    block_7:
        M2C_FIELD(arg0, s8*, 6) = var_v0;
    }
}
#undef M2C_UNK
#undef M2C_FIELD

/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EC1B4.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_special.c:player_hover_forward_stop, AGPL-3.0; proven shared with X6 by exact signature c351fcf586bf (see THIRD_PARTY.md). */

s32 try_enter_wall_cling(void*);
#define M2C_UNK s32
M2C_UNK player_set_animation_shooting(void*, M2C_UNK);
s32 func_80040BBC(void*);
void player_hover_forward_stop(Ent448C* self) {
    s32 action;

    if (func_80040B6C(self) == 0 &&
        ((s32(*)())try_enter_wall_cling)(self) == 0) {
        action = ((s32(*)())func_80040BBC)(self);
        if (action != PLAYER_BEAM_IN) {
            player_hover_set_direction(self, action);
            return;
        }
        if (self->unk46 == 0) {
            ((void (*)())player_set_animation_shooting)(self, 0x16);
            self->unk6 = 2;
            return;
        }
        func_8003F2D8(self, 0x18);
    }
}
#undef M2C_UNK

/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EC240.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 try_enter_wall_cling(void*);                       /* extern */
M2C_UNK player_set_animation_shooting(void*, M2C_UNK); /* extern */
s32 func_80040BBC(void*);                              /* extern */

void player_hover_back(void* arg0) {
    s32 temp_v0;
    s8 var_v0;

    if ((func_80040B6C() == 0) && (try_enter_wall_cling(arg0) == 0)) {
        temp_v0 = func_80040BBC(arg0);
        if (temp_v0 != 0) {
            if (temp_v0 > 0) {
                player_set_animation_shooting(arg0, 0x17);
                var_v0 = 3;
                goto block_7; // !FAKE: control flow kept from the mmx6 twin
            }
            move_object(arg0);
            func_8003F2D8(arg0, 0x19);
            return;
        }
        player_set_animation_shooting(arg0, 0x1A);
        var_v0 = 6;
    block_7:
        M2C_FIELD(arg0, s8*, 6) = var_v0;
    }
}
#undef M2C_UNK
#undef M2C_FIELD

/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EC2D0.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_special.c:player_hover_back_stop, AGPL-3.0; proven shared with X6 by exact signature b28126054f46 (see THIRD_PARTY.md). */

s32 try_enter_wall_cling(void*);
#define M2C_UNK s32
M2C_UNK player_set_animation_shooting(void*, M2C_UNK);
s32 func_80040BBC(void*);
void player_hover_back_stop(Ent448C* self) {
    s32 action;

    if (func_80040B6C(self) == 0 &&
        ((s32(*)())try_enter_wall_cling)(self) == 0) {
        action = ((s32(*)())func_80040BBC)(self);
        if (action != PLAYER_BEAM_IN) {
            player_hover_set_direction(self, action);
            return;
        }
        if (self->unk46 == 0) {
            ((void (*)())player_set_animation_shooting)(self, 0x16);
            self->unk6 = 2;
            return;
        }
        func_8003F2D8(self, 0x1A);
    }
}
