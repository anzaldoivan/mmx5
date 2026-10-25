/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001DC04.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80016D54(u8, u8); /* extern */
void func_80017D88();       /* extern */
void func_80027288();       /* extern */
void func_8002C50C(void);   /* extern */
void func_8002D004();       /* extern */
extern s8 D_8009A424;

void func_8001EF88(void* arg0) {
    if (D_8009A424 == 0) {
        func_80027288();
        func_80017D88();
        func_80016D54(0xFF, 0);
        func_8002C50C();
        func_8002D004();
        M2C_FIELD(arg0, s16*, 4) = 0;
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}
