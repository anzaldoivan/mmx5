#include "types.h"

void func_800FA908_ovl01(X4_Obj* self) {
    if (--self->unk7C == 0) {
        self->unk6 = 2;
        *(s16*)((u8*)self + 0x7E) = 0;
    }
}
