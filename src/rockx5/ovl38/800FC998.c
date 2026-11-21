#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "addr.h"

extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];

void func_800FC998_ovl38(u8* arg0) {
    set_animation(arg0, 0xD);
    *(u8**)(arg0 + 0x50) = D_800FD574_ovl38;
    *(u8**)(arg0 + 0x54) = D_800FD578_ovl38;
    *(u8**)(arg0 + 0x68) = D_800FD57C_ovl38;
    arg0[6]++;
}

extern void func_800FCAE0_ovl38(u8* a0, u8 a1);

void func_800FC9F0_ovl38(u8* a0) {
    if (((s8*)a0)[0x45] != 0) {
        play_sound(2, 0x9E, a0);
        D_1F80004C.bytes[0x91] = 7;
        func_800FCAE0_ovl38(a0, 1);
        func_800FCAE0_ovl38(a0, 2);
        func_800FCAE0_ovl38(a0, 3);
        *(s16*)(a0 + 0x7C) = 0x5A;
        a0[6]++;
    }
}

/* Adapted from mmx6 @c1c892d src/shared/rock_03/func_800EA910.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_57_frost_walrus.c:frost_walrus_blizzard_finish, AGPL-3.0; proven shared with X6 by exact signature ab19d9ae77b7 (see THIRD_PARTY.md). */

void func_800FCA74_ovl38(X4_Obj* self) {
    if (--self->unk7C == 0) {
        self->unk5 = 3;
        self->unk6 = 0;
    }
}
