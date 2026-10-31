/* Shared body (DK-5), from the banked draft of func_800FA094_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s16 D_8009A0AE;

void DEDUP_NAME(u8* obj) {
    u8* p;
    s32 v;

    func_80017248(obj);
    p = D_1F80004C.bytes;
    if (p[0x8F] == 0) {
        if (((*(s16*)(obj + 0xE) - *(s16*)(p + 0x84)) < 0
                 ? (*(s16*)(p + 0x84) - *(s16*)(obj + 0xE))
                 : (*(s16*)(obj + 0xE) - *(s16*)(p + 0x84))) >= 0x50 &&
            D_8009A0AE > *(s16*)(obj + 0xE)) {
            goto store; // !FAKE: goto kept for the matching branch layout
        }
        p = D_1F80004C.bytes;
        v = p[0x91] & 4;
    } else {
        if (((*(s16*)(obj + 0xE) - *(s16*)(p + 0x84)) < 0
                 ? (*(s16*)(p + 0x84) - *(s16*)(obj + 0xE))
                 : (*(s16*)(obj + 0xE) - *(s16*)(p + 0x84))) >= 0x50 &&
            D_8009A0AE < *(s16*)(obj + 0xE)) {
            goto store; // !FAKE: goto kept for the matching branch layout
        }
        p = D_1F80004C.bytes;
        v = p[0x91] & 8;
    }
    if (v != 0) {
    store:
        obj[6] = 3;
    } else {
        func_8002DED4(obj);
    }
}
