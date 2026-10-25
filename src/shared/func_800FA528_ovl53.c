/* Shared body (DK-5), from the banked draft of func_800FA528_ovl53 by tools/wave/gate.py rescan. */
#include "types.h"

extern signed char D_8009A424;
extern u8* D_800FB59C_ovl53;
extern u8 D_8009A1F8[];
extern u8* DEDUP_CALLEE(void);

void DEDUP_NAME(Ovl45State* s) {
    u8* p;
    u8* q;

    if (D_8009A424 == 0) {
        D_800FB59C_ovl53[4] = 2;
        p = DEDUP_CALLEE();
        if (p != 0) {
            p[0] = 1;
            p[1] = 9;
            p[0x36] = 0x11;
            *(s16*)(p + 0x34) = 0x7FFF;
            p[2] = 0;
            *(s32*)(p + 0x38) = 0x1E;
        }
        q = D_8009A1F8;
        *(s16*)(q + 0xB2) = 0;
        *(s16*)(q + 0xB6) = 0;
        q[0xAB] = 1;
        q[0xF4] = 1;
        s->unk4 = 1;
        s->unk1++;
    }
}
