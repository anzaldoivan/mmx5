#include "types.h"
#include "mmx5/globals.h"

void func_800F5C58_ovl27(Ent800F5C58* e) {
    s16 x = e->unkA;

    if (D_8009A0AA < x) {
        e->unk15 = 0;
    } else {
        e->unk15 = 0x40;
    }
}
