/* Shared body (DK-5), from the banked draft of func_800FA5B0_ovl50 by tools/wave/gate.py rescan. */
#include "types.h"

extern D_8009A1F8_AB_t D_8009A1F8;
extern D_8009A1F8_AB_t* D_800FBC88_ovl50;
extern UnkSpawn* DEDUP_CALLEE(void);

void DEDUP_NAME(Ovl45State* arg0) {
    UnkSpawn* s;

    if (++arg0->unk4 >= 30) {
        D_8009A1F8.unkAB = 0;
        if (D_800FBC88_ovl50 != 0) {
            D_800FBC88_ovl50->unk3 = 0;
        }
        D_8009A1F8.unk8 = 0;
        D_8009A1F8.unkC = 0;
        D_8009A1F8.unk3 = 1;
        D_8009A1F8.unk4C = 1;
        s = DEDUP_CALLEE();
        if (s != 0) {
            s->unk0 = 0x41;
            s->unk1 = 0x1D;
            s->unk2 = 0;
            s->unkA = 0x40;
            s->unkE = 0x44;
            s->unk54 = 6;
        }
        arg0->unk4 = 1;
        arg0->unk1++;
    }
}
