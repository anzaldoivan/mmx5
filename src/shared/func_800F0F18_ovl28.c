#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

#define SCRATCH_CTX D_1F80004C.ctx0f18

void func_800F0F18_ovl28(Ent0F18* a0) {
    Ctx0F18* c;

    animate_object(a0);
    move_object(a0);
    c = SCRATCH_CTX;
    if (--c->unk80 == 0) {
        a0->unk67 = -1;
        a0->unk5 = 6;
        a0->unk6 = 0;
    }
}
