#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/player.h"
#include "mmx5/sound.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003D850.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_common.c:player_entry_beam_in, AGPL-3.0; proven shared with X6 by exact signature 6b996a39570c (see THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define FIXED(x) ((s32)((x) * 0x10000))

void func_8003D72C(X4_Obj* self) {
    func_8003B33C(self, 1);
    play_sound(1, 0xD, self);
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_vel.val = FIXED(-8);
    self->unk2C = 0;
    M2C_FIELD(self, s8*, 0x67) = -1;
    self->unk5 = PLAYER_BEAM_IN;
}
#undef M2C_FIELD
#undef FIXED

extern void* player_spawn_visual(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern void load_buffered_palette(s32 arg0, s32 arg1, s32 arg2);
extern void func_8003B65C(u8* arg0);

void func_8003D784(u8* arg0) {
    u8* d;
    s32 v;

    D_800D1DC0.s[0] = 1;
    d = g_playthrough_state.u;
    v = d[0x49];
    arg0[0xFA] = v;
    *(s32*)(arg0 + 0xFC) =
        *(s32*)(g_playthrough_state.u + arg0[0xFA] * 4 + 0x88);
    if (v == 3) {
        arg0[0xC9] = 0;
        arg0[0x14A] = 0;
        player_spawn_visual(1, 0x1B, 8, 0);
        player_spawn_visual(1, 0x1B, 9, 0);
        load_buffered_palette(0x49, 0x14, 1);
    } else {
        arg0[0xC9] = d[0x4C];
        arg0[0x14A] = d[0x4B];
    }
    func_8003B65C(arg0);
    ((s8*)arg0)[0xD5] = -1;
    arg0[0x67] = 1;
    arg0[0xD8] = 0x29;
    arg0[5] = 0x12;
    arg0[6] = 1;
}
