#include "types.h"
#include "addr.h"

extern void func_8002DF54(Ent2BF8*);
extern s32 func_800F37C4_ovl07(Ent2BF8*);

void func_800F3738_ovl07(Ent2BF8* e) {
    func_8002DF54(e);
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
