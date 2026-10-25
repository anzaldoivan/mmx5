/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80020D18.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/object_update.c:func_80021D20, AGPL-3.0; proven shared with X6 by exact signature 95cf5435ad21 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern X4_Obj D_80091C38;
void func_8002385C(u16, u8, u8);
void func_80023CC0(X4_Obj*);

void func_80022E80(void) {
    if (D_80091C38.y_pos.bytes[0] != 0) {
        func_80023CC0(&D_80091C38);
    } else if (M2C_FIELD(&D_80091C38, s16*, 0x10) != 0) {
        func_8002385C(M2C_FIELD(&D_80091C38, s16*, 0x10) & ~0x8000, 0xFF, 0);
    }
}
