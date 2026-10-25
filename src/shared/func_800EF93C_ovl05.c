/* Shared body (DK-5), from the banked draft of func_800EF93C_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8002D800(u8* a0);
extern s32 func_8002D9EC(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if (func_8002D800(obj) != 0 ||
        (func_8002D9EC(obj, 0x30, 0x10), *(s8*)(obj + 0x46) == 0)) {
        obj[4]++;
    }
}
