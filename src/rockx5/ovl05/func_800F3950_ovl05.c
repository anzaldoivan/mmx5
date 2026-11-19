#include "types.h"

extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_800F56C8_ovl05[];

void func_800F3950_ovl05(Obj3950* self) {
    u32 t = ++self->unk7C.w;
    self->unk3 = self->unk7C.b & 4;
    if (t > 60) {
        self->unk3 = 0;
        func_8004D4F4(8, D_800F56C8_ovl05, (u8*)self);
        self->unk4++;
    }
}
