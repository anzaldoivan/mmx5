/* Shared body (DK-5), from the banked draft of func_800F63B4_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(Ent08D8*);
extern void func_8002DED4(Ent08D8*);

void DEDUP_NAME(Ent08D8* e) {
    if (e->unk70 & 8) {
        e->unk24 = 0x40000;
        e->unk2C = 0x6000;
        e->unk6++;
    }
    func_80017248(e);
    func_8002DED4(e);
}
