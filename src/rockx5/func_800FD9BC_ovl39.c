#include "types.h"

void func_800FD9BC_ovl39(Obj800FD9BC* self) {
    if (--self->unk82 == 0) {
        if (self->unkA < 0x1210) {
            self->unk20 = 0x8000;
        } else {
            self->unk20 = -0x8000;
        }
        self->unk82 = 0;
        self->unk84 = 0;
        self->unk85 = 3;
        self->unk6++;
    }
}
