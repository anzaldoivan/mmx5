#include "types.h"

extern void func_80017248(Ent08D8*);
extern void func_8002DED4(Ent08D8*);

void func_800F08D8_ovl29(Ent08D8* e) {
    func_80017248(e);
    if (e->unk70 & 8) {
        e->unk5 = 5;
        e->unk6 = 0;
        e->unk24 = 0;
        e->unk2C = 0;
        e->unk20 = 0;
        e->unk28 = 0;
        e->unk67 = 0;
    } else {
        func_8002DED4(e);
    }
}
