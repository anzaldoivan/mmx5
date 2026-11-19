#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F5590_ovl29(Ent08D8* e) {
    animate_object(e);
    apply_object_motion(e);
    if (e->unk24 < 0) {
        e->unk6++;
    }
}
