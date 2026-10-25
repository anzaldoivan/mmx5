/* Shared body (DK-5), from the banked draft of func_800FA428_ovl44 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern D_8009A1F8_t D_8009A1F8;

void DEDUP_NAME(UnkObj* arg0) {
    D_8009A1F8_t* p;

    if (D_80091C44 == 0) {
        p = &D_8009A1F8;
        *(s32*)&p->pad58[4] = 0xC00000;
        *(s32*)&p->pad60[0] = 0;
        p->unkA0 = 1;
        p->unk57 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
