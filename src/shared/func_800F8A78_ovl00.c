/* Shared body (DK-5), from the banked draft of func_800F8A78_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void DEDUP_NAME(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        func_800171E8(obj, 3);
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
