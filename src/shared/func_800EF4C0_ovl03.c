/* Shared body (DK-5), from the banked draft of func_800EF4C0_ovl03 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC380.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_32_bomb_bat.c:bomb_bat_hover_start, AGPL-3.0; proven shared with X6 by exact signature c21d8b683171 (see THIRD_PARTY.md). */
#include "types.h"
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))

#define M2C_UNK s32
M2C_UNK func_80017248();
void DEDUP_NAME(X4_Obj* self) {
    ((void (*)())func_80017248)(ANIMATED_OBJECT(self));
    self->unk7C = 0xC8;
    self->unk6++;
}
