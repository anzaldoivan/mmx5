#include "types.h"
#include "addr.h"

extern void func_8002DF54(Ent3594*);
extern s32 func_800F37C4_ovl07(Ent3594*);

void func_800F3594_ovl07(Ent3594* e) {
    func_8002DF54(e);
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
