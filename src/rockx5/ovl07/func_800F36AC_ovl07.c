#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/object.h"
#include "addr.h"

void func_800F36AC_ovl07(Ent2BF8* e) {
    move_object(e);
    if (D_1F80004C.scr36ac->unk80 - 0x30 >= e->unkA) {
        e->unk20 = 0x8000;
        if (D_1F80004C.scr36ac->unk84) {
            D_1F80004C.scr36ac->unk84 = 0;
        } else if (func_800F37C4_ovl07(e)) {
            e->unk20 = 0x30000;
        }
        e->unk5 = 5;
    }
}
