/* Shared body (DK-5), from the banked draft of func_800F5B3C_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_800FB61E_ovl09;
extern u8 D_800FAD58_ovl09[][6];
extern void func_80017248(Ent5B3C*);
extern void func_8002DED4(Ent5B3C*);

void DEDUP_NAME(Ent5B3C* e) {
    if (e->unkE <= D_800FB61E_ovl09) {
        e->unkE = D_800FB61E_ovl09;
        e->unk24 = 0;
        e->unk2C = 0;
        e->unk5 = D_800FAD58_ovl09[e->unk96][e->unk97++];
        e->unk6 = 0;
    }
    func_80017248(e);
    func_8002DED4(e);
}
