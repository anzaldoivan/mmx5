/* Shared body (DK-5), from the banked draft of func_800F1608_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8002DED4(u8* obj);

void DEDUP_NAME(u8* obj) {
    s32 v;

    func_80017248(obj);
    func_8002DED4(obj);
    v = *(s32*)(obj + 0x24);
    if (v == 0) {
        *(s16*)(obj + 0x7C) = 0x28;
        *(s32*)(obj + 0x24) = v;
        *(s32*)(obj + 0x2C) = -0x1000;
        obj[6]++;
    }
}
