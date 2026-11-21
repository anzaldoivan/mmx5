#include "types.h"
#include "mmx5/globals.h"

#define D_800FA214_ovl00 D_800F5800_ovl05

#define func_800EEB64_ovl00 func_800F3914_ovl05
#include "shared/func_800EEB64_ovl00.c"
#undef func_800EEB64_ovl00
#undef D_800FA214_ovl00

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

extern s8 D_800D1C0F;

void func_800F39BC_ovl05(u8* arg0) {
    u8* p = g_Player;

    if ((p[0x5C] & 0x7F) && *(s16*)(p + 0xA) >= 0x1134) {
        D_800D1C0F = 0x40;
        func_8002D720(arg0);
    }
}
