#include "types.h"
#include "mmx5/globals.h"

void func_800F0D1C_ovl28(Ent800F0D1C* e) {
    if (D_8009A0AA - e->y >= 0xB0) {
        e->unk15 = 0x40;
        e->unk4 = 1;
        e->unk5 = 3;
    }
}
