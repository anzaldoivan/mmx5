#include "types.h"
#include "mmx5/globals.h"

void func_800F1074_ovl11(X4_Obj*);

void func_800F0D54_ovl11(X4_Obj* self) {
    animate_object(self);
    if (--self->unk7C == 0) {
        func_800F1074_ovl11(self);
        self->unk7C = 0x3C;
        self->unk6++;
    }
}
