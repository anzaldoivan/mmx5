/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80037F34.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player_special.c:player_zero_ryuenjin_rise, AGPL-3.0; proven shared with X6 by exact signature dff51a405822 (see THIRD_PARTY.md). */
#include "types.h"
void func_80017248(u8* obj);
#define M2C_UNK s32
s32 func_80039ECC(void*);
M2C_UNK func_8002DF54(void*);

void func_80037B4C(X4_Obj* self) {
    if (func_80039ECC(self) == 0) {
        func_8002DF54(self);
        func_80017248(self);
    }
}
