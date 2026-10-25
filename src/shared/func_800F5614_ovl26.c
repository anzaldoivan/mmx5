/* Shared body (DK-5), from the banked draft of func_800F5614_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (*(s32*)(obj + 0x24) < 0) {
        func_800171E8(obj, 0x15);
        obj[6]++;
    }
}
