/* Shared body (DK-5), from the banked draft of func_800F0FEC_ovl12 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_45/func_800FC74C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016490(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_80017248(void*);                   /* extern */
M2C_UNK func_8002D6FC();                        /* extern */
M2C_UNK func_8002D9EC(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002DF54(void*);                   /* extern */
extern s8 D_800D1C0F;

void DEDUP_NAME(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        D_800D1C0F = 0x10;
        func_8002D6FC();
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_80016490(2, 0x48, arg0);
        M2C_FIELD(arg0, s32*, 0x24) = 0x80000;
    }
    func_8002D9EC(arg0, 0x40, 0x40);
    func_80017248(arg0);
    func_8002DF54(arg0);
}
