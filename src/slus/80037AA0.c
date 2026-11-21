#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s8 D_800D1C0F;
extern void func_8003B1A8(u8* a0);
extern void func_80039F1C(u8* a0);

void func_80037AA0(u8* a0) {
    if (D_800D1C0F != 0) {
        func_8003B1A8(a0);
        return;
    }
    if (*(s8*)(a0 + 0x45) == 0) {
        *(s32*)(a0 + 0x20) = *(s32*)(a0 + 0x100);
    } else {
        *(s32*)(a0 + 0x20) = *(s32*)(a0 + 0x104);
    }
    if (a0[0x15] == 0) {
        *(s32*)(a0 + 0x20) = -*(s32*)(a0 + 0x20);
    }
    move_object(a0);
    animate_object(a0);
    if (a0[0xD2] == 0) {
        func_80039F1C(a0);
    }
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80037F34.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_special.c:player_zero_ryuenjin_rise, AGPL-3.0; proven shared with X6 by exact signature dff51a405822 (see THIRD_PARTY.md). */

void func_80037B4C(X4_Obj* self) {
    if (func_80039ECC(self) == 0) {
        move_object(self);
        animate_object(self);
    }
}
