/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003DAF4.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_common.c:player_spawn_death_orb, AGPL-3.0; proven shared with X6 by exact signature 76c0b9feb772 (see THIRD_PARTY.md). */
#include "types.h"
#define NULL ((void*)0)
void* func_8002D27C();

void func_8003DAA4(s8 direction) {
    X4_Obj* obj;

    obj = func_8002D27C();
    if (obj != NULL) {
        obj->active = 0x21;
        obj->id = 0x11;
        obj->unk2 = direction;
        obj->state = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
    }
}
