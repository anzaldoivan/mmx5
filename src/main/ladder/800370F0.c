#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s32 try_leave_ladder(Ent371CC*);
extern s32 player_check_ladder_shoot(Ent371CC*);
extern s32 func_80043A80(Ent371CC*);
extern void player_set_animation_frame(Ent371CC*, s32, s32);
extern void func_8003B148(Ent371CC*);

void player_ladder_up(Ent371CC* arg0) {
    s8 temp_s0;
    u16 flags;

    func_80043B88(arg0);
    if (try_leave_ladder(arg0) == 0 && player_check_ladder_shoot(arg0) == 0 &&
        func_80043A80(arg0) == 0) {
        if (arg0->unk80 & 2) {
            arg0->unk15 = 0;
        }
        if (arg0->unk80 & 1) {
            arg0->unk15 = 0x40;
        }
        flags = arg0->unk7C;
        if (flags & 4) {
            animate_object(arg0);
            move_object(arg0);
        } else if (flags & 8) {
            temp_s0 = arg0->unk44;
            player_set_animation_frame(arg0, 0x20, arg0->unk45);
            arg0->unk44 = temp_s0;
            func_8003B148(arg0);
        }
    }
}

extern s32 try_leave_ladder(Ent371CC*);
extern s32 player_check_ladder_shoot(Ent371CC*);
extern s32 func_80043A80(Ent371CC*);
extern void player_set_animation_frame(Ent371CC*, s32, s32);
extern void func_8003B0EC(Ent371CC*);

void player_ladder_down(Ent371CC* arg0) {
    s8 temp_s0;
    u16 flags;

    func_80043B88(arg0);
    if (try_leave_ladder(arg0) == 0 && player_check_ladder_shoot(arg0) == 0 &&
        func_80043A80(arg0) == 0) {
        if (arg0->unk80 & 2) {
            arg0->unk15 = 0;
        }
        if (arg0->unk80 & 1) {
            arg0->unk15 = 0x40;
        }
        flags = arg0->unk7C;
        if (flags & 4) {
            temp_s0 = arg0->unk44;
            player_set_animation_frame(arg0, 0x1F, arg0->unk45);
            arg0->unk44 = temp_s0;
            func_8003B0EC(arg0);
        } else if (flags & 8) {
            animate_object(arg0);
            move_object(arg0);
        }
    }
}
