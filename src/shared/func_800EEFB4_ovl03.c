/* Shared body (DK-5), from the banked draft of func_800EEFB4_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(Ent08D8*);
extern void func_8002DED4(Ent08D8*);

void DEDUP_NAME(Ent08D8* e) {
    func_80017248(e);
    if (e->unk70 & 8) {
        e->unk5 = 2;
        e->unk6 = 0;
        e->unk24 = 0;
        e->unk2C = 0;
        e->unk67 = 0;
    } else {
        func_8002DED4(e);
    }
}
