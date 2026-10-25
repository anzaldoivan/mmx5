/* Shared body (DK-5), from the banked draft of func_800F0CA4_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void DEDUP_NAME(u8* obj) {
    if (*(s32*)(obj + 0x8C) != 1) {
        *(s32*)(obj + 0x8C) = *(s32*)(obj + 0x8C) - 1;
    }
    func_80017248(obj);
    func_8002DED4(obj);
    if (*(s32*)(obj + 0x20) == 0) {
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(u8*)(obj + 0x88) = 0;
        *(s16*)(obj + 0x7C) = 10;
        *(u8*)(obj + 0x6) = 3;
    }
}
