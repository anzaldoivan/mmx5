#include "types.h"
#include "mmx5/movement.h"

void func_800F1B34_ovl10(Ent08D8* e) {
    apply_object_motion(e);
    if (e->unk70 & 8) {
        e->unk24 = 0;
        e->unk2C = 0;
        e->unk20 = 0;
        e->unk28 = 0;
        e->unk67 = 0;
        e->unk5 = 2;
        e->unk6 = 0;
    }
}
