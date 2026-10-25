#include "types.h"

void func_800FD8F4_ovl39(Obj800FD9BC* self) {
    if (--self->unk82 == 0) {
        if (self->unkA < 0x1210) {
            self->unk20 = 0x8000;
        } else {
            self->unk20 = -0x8000;
        }
        self->unk6++;
    }
}
