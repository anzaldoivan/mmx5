/* Shared body (DK-5), from the banked draft of func_800EEC98_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);
extern Obj8002CC08 D_80098120[];
extern u8 D_8009A0A0[];

void DEDUP_NAME(u8* o) {
    Obj8002CC08* p;

    if (*(s8*)(o + 0x67) != 0) {
        return;
    }
    if (o[0x80] & 1) {
        return;
    }
    if (o[0x82] != 0) {
        o[0x82]--;
        return;
    }
    for (p = D_80098120; p < D_80098120 + 32; p++) {
        if (p->active == 0) {
            continue;
        }
        if (((s8*)p)[1] != 0) {
            continue;
        }
        if (o[0x15] != 0) {
            if (D_8009A0A0[0x15] == 0 &&
                *(s32*)(o + 8) < *(s32*)(D_8009A0A0 + 8) &&
                ((*(s16*)((u8*)p + 0xE) - *(s16*)(o + 0xE)) < 0
                     ? (*(s16*)(o + 0xE) - *(s16*)((u8*)p + 0xE))
                     : (*(s16*)((u8*)p + 0xE) - *(s16*)(o + 0xE))) < 0x18 &&
                *(s16*)((u8*)p + 0xA) < *(s16*)(o + 0xA) + 0x80) {
                o[0x80] |= 1;
            }
        } else {
            if (D_8009A0A0[0x15] != 0 &&
                *(s32*)(o + 8) > *(s32*)(D_8009A0A0 + 8) &&
                ((*(s16*)((u8*)p + 0xE) - *(s16*)(o + 0xE)) < 0
                     ? (*(s16*)(o + 0xE) - *(s16*)((u8*)p + 0xE))
                     : (*(s16*)((u8*)p + 0xE) - *(s16*)(o + 0xE))) < 0x18 &&
                *(s16*)(o + 0xA) - 0x80 < *(s16*)((u8*)p + 0xA)) {
                o[0x80] |= 1;
            }
        }
        if (o[0x80] & 1) {
            o[5] = 3;
            o[6] = 0;
            DEDUP_CALLEE(o, 5);
            return;
        }
    }
}
