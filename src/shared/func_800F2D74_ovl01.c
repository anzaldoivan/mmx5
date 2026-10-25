/* Shared body (DK-5), from the banked draft of func_800F2D74_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (*(s32*)(obj + 0x24) < 0) {
        obj[0x5] = 7;
        obj[0x6] = 0;
        *(s32*)(obj + 0x2C) = 0x5200;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s8*)(obj + 0x67) = -1;
    }
}
