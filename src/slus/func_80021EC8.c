/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001FF78.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002BBF8(); /* extern */
extern s8 D_8009A424;

void func_80021EC8(void* arg0) {
    if (D_8009A424 == 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        func_8002BBF8();
        M2C_FIELD(arg0, s8*, 7) = 0;
        M2C_FIELD(arg0, s32*, 0x34) = 0;
    }
}
