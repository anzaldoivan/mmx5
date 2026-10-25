/* Shared body (DK-5), from the banked draft of func_800F2970_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define G D_1F80004C.bytes

extern void func_800F2E10_ovl00(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    s32 s = (signed char)obj[0x45];

    if (s == 1) {
        func_800F2E10_ovl00(obj);
    } else if (s == 2) {
        func_800171E8(obj, 6);
        if (--G[0x84] == 0) {
            func_800171E8(obj, 5);
            (*(u8**)(G + 0x80))[0x8A] = 0;
            obj[5] = s;
            obj[6] = 0;
        }
    }
}
