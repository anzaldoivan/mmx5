#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F0EC8_ovl11(Ent08D8* e) {
    animate_object(e);
    if (e->unk70 & 8) {
        e->unk5 = 2;
        e->unk6 = 0;
        e->unk24 = 0;
        e->unk2C = 0;
        e->unk20 = 0;
        e->unk28 = 0;
        e->unk67 = 0;
    } else {
        apply_object_motion(e);
    }
}
