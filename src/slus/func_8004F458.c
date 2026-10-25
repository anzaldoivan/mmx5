/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800494DC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_00_wall_slide_dust.c:wall_slide_dust_init, AGPL-3.0; proven shared with X6 by exact signature 4a86628af3e4 (see THIRD_PARTY.md). */
#include "types.h"
#include "addr.h"
void func_8004F5CC(X4_Obj* arg0, X4_Obj* arg1);
#define SP(offset) (0x1F800000 + (offset))
#define M2C_UNK s32
extern u32* D_8007B2E8[];
M2C_UNK func_8002D9EC(void*, M2C_UNK, M2C_UNK);
s32 func_800171E8(void*, s32);

void func_8004F458(X4_Obj* arg0, X4_Obj* arg1) {
    arg0->on_screen = 1;
    arg0->unk38 = 0;
    arg0->unk3C = (void*)((s8*)D_1F80001C.s32s + D_1F80001C.s32s[1]);
    arg0->animation_table = &D_8007B2E8;
    arg0->unk40 = 0;
    arg0->unk42 = 0x7804;
    arg0->unk16 = 1;
    func_8004F5CC(arg0, arg1);
    func_800171E8(arg0, 3);
    arg0->state++;
    func_8002D9EC(arg0, 0x20, 0x20);
}
