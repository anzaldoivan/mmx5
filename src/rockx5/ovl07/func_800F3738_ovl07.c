#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/object.h"
#include "addr.h"

void func_800F3738_ovl07(Ent2BF8* e) {
    move_object(e);
    if (e->unkA >= D_1F80004C.scr36ac->unk80 + 0x30) {
        e->unk20 = -0x8000;
        if (D_1F80004C.scr36ac->unk84) {
            D_1F80004C.scr36ac->unk84 = 0;
        } else if (func_800F37C4_ovl07(e)) {
            e->unk20 = -0x30000;
        }
        e->unk5 = 4;
    }
}
