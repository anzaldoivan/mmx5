/* Shared body (DK-5), from the banked draft of func_800EFC38_ovl03 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC9D0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017248();
M2C_UNK func_8002DF54();
s32 func_8002DFF8(void* arg0, s32 arg1, s32 arg2);
void func_8002E058(void*, s32);
extern s32 D_8009A0A0;
#define D_8009A0A0 (*(X4_Obj*)&D_8009A0A0)

void DEDUP_NAME(X4_Obj* self) {
    ((void (*)())func_80017248)();
    if (--self->unk7C == 0) {
        self->unk5 = 8;
        self->unk6 = 0;
    }
    M2C_FIELD(self, s32*, 0x90) = M2C_FIELD(self, s32*, 0x90) + 1;
    M2C_FIELD(self, s32*, 0x90) = M2C_FIELD(self, u8*, 0x90) & 3;
    if (M2C_FIELD(self, u8*, 0x90) == 0) {
        func_8002E058(self, func_8002DFF8(self, D_8009A0A0.x_pos.val,
                                          D_8009A0A0.y_pos.val) &
                                0xFF);
    }
    func_8002DF54(self);
}
#undef D_8009A0A0
