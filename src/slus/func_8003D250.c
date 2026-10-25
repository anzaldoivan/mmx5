/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003D2BC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_common.c:player_spawn_wall_slide_dust, AGPL-3.0; proven shared with X6 by exact signature 8e04af3111c5 (see THIRD_PARTY.md). */
#include "types.h"
#define NULL ((void*)0)
X4_Obj* func_8002D0E4(void);

void func_8003D250(X4_Obj* self) {
    X4_Obj* visual_obj;

    visual_obj = func_8002D0E4();
    if (visual_obj != NULL) {
        visual_obj->active = 0x21;
        visual_obj->id = 0;
        visual_obj->bg_offset = self->bg_offset;
        visual_obj->state = 0;
        visual_obj->unk5 = 0;
        visual_obj->unk6 = 0;
    }
}
