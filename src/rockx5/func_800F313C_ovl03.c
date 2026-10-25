#include "types.h"

extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_800F9E44_ovl03[];

void func_800F313C_ovl03(Obj3950* self) {
    u32 t = ++self->unk7C.w;
    self->unk3 = self->unk7C.b & 4;
    if (t > 30) {
        func_8004D4F4(5, D_800F9E44_ovl03, (u8*)self);
        self->unk3 = 0;
        self->unk4 = 2;
    }
}
