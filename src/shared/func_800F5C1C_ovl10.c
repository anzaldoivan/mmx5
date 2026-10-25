/* Shared body (DK-5), from the banked draft of func_800F5C1C_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    *(s32*)(obj + 0x2C) = 0x3800;
    func_80017248(obj);
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        if (*(s8*)(obj + 2) == 2) {
            (*(u8**)(obj + 0x80))[0x98] = 0;
        }
        func_800171E8(obj, 0x15);
        obj[6] = 1;
    }
}
