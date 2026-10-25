/* Shared body (DK-5), from the banked draft of func_800F826C_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void DEDUP_NAME(u8* obj) {
    *(s32*)(obj + 0x24) = -*(s32*)(obj + 0x24);
    if (++*(s16*)(obj + 0x7C) == 0x78) {
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0x8000;
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
