#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/object.h"
#include "addr.h"

void func_800F3594_ovl07(Ent3594* e) {
    move_object(e);
    if (D_1F80004C.scr3594->unk82 - 0x20 >= e->unkE) {
        e->unk24 = -0x8000;
        if (D_1F80004C.scr3594->unk84) {
            D_1F80004C.scr3594->unk84 = 0;
        } else if (func_800F37C4_ovl07(e)) {
            e->unk24 = 0xFFFD0000;
        }
        e->unk5 = 3;
    }
}
