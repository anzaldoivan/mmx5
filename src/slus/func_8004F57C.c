/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80049670.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_00_wall_slide_dust.c:wall_slide_dust_fade, AGPL-3.0; proven shared with X6 by exact signature 246e79a6823b (see THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
M2C_UNK func_80017248();
M2C_UNK func_8002D6FC(void*, void*);
M2C_UNK func_8002D9EC(void*, M2C_UNK, M2C_UNK);
void func_8004F57C(ObjEE5C* arg0, X4_Obj* arg1) {
    ((void (*)())func_80017248)(arg0);
    if (arg0->unk46 < 0) {
        ((void (*)())func_8002D6FC)(arg0);
        return;
    }
    ((void (*)())func_8002D9EC)(arg0, 0x20, 0x20);
}
