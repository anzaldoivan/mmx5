/* Adapted from mmx6 @c1c892d src/shared/rock_08/func_800E99EC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_13_ride_chaser_jet.c:ride_chaser_jet_main, AGPL-3.0; proven shared with X6 by exact signature ca898a8565aa (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))
#define BASE_OBJECT(object) ((X4_Obj*)(object))
#define M2C_UNK s32
extern u8 D_80100924_ovl07[16];
void func_8002D9EC(X4_Obj*, s32, s32);
void func_80017214(X4_Obj*, s32, s32);
M2C_UNK func_80017248();

void func_800F17D4_ovl07(ObjFAF30* arg0) {
    Obj5E5C* player;
    u8 animation;
    s16 previous_frame;
    u8 frame;
    u8 next_animation;

    player = M2C_FIELD(arg0, Obj5E5C**, 0x50);
    if (M2C_FIELD(player, s8*, 0x4) != 2) {
        frame = player->unk47;
        previous_frame = arg0->unk56;
        next_animation = D_80100924_ovl07[frame];
        if (frame != previous_frame &&
            (animation = next_animation & 0xFF) != arg0->unk54) {
            func_80017214(ANIMATED_OBJECT(arg0), animation,
                          M2C_FIELD(arg0, s8*, 0x45));
            frame = player->unk47;
            arg0->unk56 = frame;
            arg0->unk54 = next_animation;
        }
        M2C_FIELD(arg0, s16*, 0xA) = player->unkA;
        M2C_FIELD(arg0, s16*, 0xE) = player->unkE;
        func_80017248(ANIMATED_OBJECT(arg0));
        func_8002D9EC(BASE_OBJECT(arg0), 0x10, 0x10);
        return;
    }
    arg0->unk4 = 2;
}
