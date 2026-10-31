/* Shared body (DK-5), from the banked draft of func_800F4280_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    s8 st;

    if (((s8*)obj)[7] == 2) {
        if (((s8*)obj)[0x45] != 2) {
            DEDUP_CALLEE(obj);
        }
        return;
    }
    DEDUP_CALLEE(obj);
    if (obj[0x8A] == 2) {
        if (((s8*)obj)[2] != 0) {
            st = ((s8*)obj)[7];
            if (st == 1 && ((s8*)*(u8**)(obj + 0x80))[7] == st &&
                ((s8*)obj)[0x45] == 3) {
                obj[0x87] = 0x3C;
                obj[6] = 7;
            }
            return;
        }
        if (((s8*)obj)[0x98] != 0) {
            st = ((s8*)obj)[7];
            if (st != 1 || ((s8*)*(u8**)(obj + 0x80))[7] != st) {
                return;
            }
            goto tail; // !FAKE: goto kept for the matching branch layout
        }
    }
    if (((s8*)obj)[7] == 1) {
    tail:
        if (((s8*)obj)[0x45] == 3) {
            obj[6] = 7;
        }
    }
}
