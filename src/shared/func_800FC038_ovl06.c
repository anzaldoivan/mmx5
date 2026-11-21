#include "types.h"

extern void (*D_800FF73C_ovl06[])(Obj800FC038*);

void func_800FC038_ovl06(Obj800FC038* self) {
    if (((Obj800FC038*)self->unk50)->unk4 == 2) {
        self->unk4 = 2;
        self->unk3 = 0;
    } else {
        D_800FF73C_ovl06[self->unk5](self);
    }
}
