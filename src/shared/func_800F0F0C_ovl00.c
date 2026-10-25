/* Shared body (DK-5), from the banked draft of func_800F0F0C_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern int DEDUP_CALLEE();
extern u8 D_8009A197;
extern void (*D_800FA970_ovl00[])(Ent50*);

void DEDUP_NAME(Ent50* arg0) {
    s8 state = arg0->unk50->unk4;

    if (state != 1) {
        DEDUP_CALLEE(arg0);
        return;
    }
    if (D_8009A197 == 0) {
        arg0->unk18 = arg0->unk8;
        arg0->unk1C = arg0->unkC;
        D_800FA970_ovl00[arg0->unk5](arg0);
    }
    if (arg0->unk50->unk96 == 0) {
        arg0->unk3 = 0;
    } else {
        arg0->unk3 = state;
    }
}
