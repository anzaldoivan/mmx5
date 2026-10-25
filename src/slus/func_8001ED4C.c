/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001D930.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/game_info.c:func_8001D6DC, AGPL-3.0; proven shared with X6 by exact signature 07619b425e9d (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
void func_80022618(void);
extern s8 D_8009A424;
#define D_8009A424 (*(s8(*)[]) & D_8009A424)
void func_800272B4();

#define M2C_UNK s32
void func_80024698(void);
void func_8001ED4C(struct X4_GameInfo* arg0) {
    if (D_8009A424[0] == 0) {
        if (M2C_FIELD(arg0, s8*, 0xE) == 1) {
            M2C_FIELD(arg0, s8*, 0x0) = 6;
        } else {
            M2C_FIELD(arg0, s8*, 0x0) = 1;
        }
        return;
    }

    switch (M2C_FIELD(arg0, s8*, 0xE)) {
    case 0:
        break;
    case 1:
        func_80022618();
        func_800272B4();
        break;
    case 2:
        func_800272B4();
        break;
    case 3:
        func_80022618();
        func_80024698();
        break;
    }
}
#undef D_8009A424
