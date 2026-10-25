#include "types.h"
#include "addr.h"

extern void func_8002DF54(Ent3620*);
extern s32 func_800F37C4_ovl07(Ent3620*);

void func_800F3620_ovl07(Ent3620* e) {
    func_8002DF54(e);
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
