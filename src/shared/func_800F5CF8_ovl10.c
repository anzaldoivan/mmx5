/* Shared body (DK-5), from the banked draft of func_800F5CF8_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_80016490(s32, s32, void*);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (*(signed char*)(obj + 0x45) == 0x10) {
        func_80016490(2, 0x5B, obj);
    }
    if (*(signed char*)(obj + 0x45) == 1) {
        obj[0x86] = 1;
        obj[0x3] = 0;
    }
}
