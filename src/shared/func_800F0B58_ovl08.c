/* Shared body (DK-5), from the banked draft of func_800F0B58_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern s16 D_8009A0AA;

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if (--*(s16*)(obj + 0x7C) != 0) {
        return;
    }
    obj[0x8A] = 1;
    if (obj[0x15] == 0) {
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            goto hit; // !FAKE: goto kept for the matching branch layout
        }
        goto miss; // !FAKE: goto kept for the matching branch layout
    }
    if (D_8009A0AA < *(s16*)(obj + 0xA)) {
    hit:
        func_800171E8(obj, 2);
        obj[5] = 4;
        obj[6] = 1;
        *(s16*)(obj + 0x7C) = 1;
        return;
    }
miss:
    *(s16*)(obj + 0x7C) = 20;
    obj[6] = 1;
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = 0xFFFC0000;
    } else {
        *(s32*)(obj + 0x20) = 0x40000;
    }
}
