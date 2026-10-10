#include "types.h"

#define D_1F80004C (*(Scr780**)0x1F80004C)

extern s16 D_8009A1F8[];
extern void func_8001296C(s32);
extern s32 func_80016490(s32, s32, s32);
extern void func_8002A600(s32, s32, s32);
extern void func_800EF91C_ovl00(s32, s16, s16, s16, s16, s32);

void func_800EF780_ovl00(Self780* self) {
    Scr780* scr = D_1F80004C;
    Pl780* pl;

    if (scr->unk90 != 0) {
        return;
    }
    if (self->unk70 & 1) {
        scr->unk80->unk87 = 1;
        func_8001296C(8);
        func_80016490(5, 5, 0);
        if (D_8009A1F8[0x10] == D_8009A1F8[7]) {
            func_8002A600(8, 4, 2);
        }
        func_800EF91C_ovl00(0x12, self->unkA + 0x10, self->unkE - 0x14,
                            self->unkA + 0x20, self->unkE, 3);
        func_800EF91C_ovl00(0x14, self->unkA + 0x10, self->unkE,
                            self->unkA + 0x20, self->unkE + 0x14, 3);
        self->unk6 = 6;
        pl = D_1F80004C->unk80;
        pl->unk8A = self->unkA - pl->unkA;
    }
    self->unkA = D_1F80004C->unk80->unkA + D_1F80004C->unk80->unk8A;
    self->unkE = D_1F80004C->unk80->unkE;
}
