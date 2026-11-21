#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

#define SCRATCH_CTX D_1F80004C.ctx0f18

void func_800F0E04_ovl28(Ent0E04* a0) {
    Ctx0F18* c;

    animate_object(a0);
    move_object(a0);
    c = SCRATCH_CTX;
    if (--c->unk80 == 0) {
        a0->unk5 = 3;
        a0->unk6 = 0;
    }
}
