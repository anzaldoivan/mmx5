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

void func_800F3620_ovl07(Ent3620* e) {
    move_object(e);
    if (e->unkE >= D_1F80004C.scr3594->unk82 + 0x20) {
        e->unk24 = 0x8000;
        if (D_1F80004C.scr3594->unk84) {
            D_1F80004C.scr3594->unk84 = 0;
        } else if (func_800F37C4_ovl07(e)) {
            e->unk2C = 0x30000;
        }
        e->unk5 = 2;
    }
}

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
