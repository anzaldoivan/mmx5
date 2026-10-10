#include "types.h"

extern void func_80017248(Ent08D8*);
extern void func_8002DED4(Ent08D8*);

void func_800F5590_ovl29(Ent08D8* e) {
    func_80017248(e);
    func_8002DED4(e);
    if (e->unk24 < 0) {
        e->unk6++;
    }
}
