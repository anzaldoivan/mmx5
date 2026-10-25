/* Shared body (DK-5), from the banked draft of func_800F6D98_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    func_8002DF54(obj);
    func_80017248(obj);
    if (obj[0x70] & 8) {
        func_800171E8(obj, 13);
        obj[6]++;
    }
}
