#include "types.h"
#include "addr.h"

void func_800F572C_ovl27(Obj800F2688* self) {
    if (--self->unk7C == 0) {
        func_800F59D8_ovl27(self);
        D_1F80004C.bytes[0x88] = 0;
    }
}
