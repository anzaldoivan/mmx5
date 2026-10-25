/* Shared body (DK-5), from the banked draft of func_800F1590_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8002DF54(u8* a0);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if (*(s16*)(obj + 0x7C) != 0) {
        *(s16*)(obj + 0x7C) -= 1;
    } else {
        func_8002DF54(obj);
        *(s16*)(obj + 0x7E) -= 1;
        if (*(s16*)(obj + 0x7E) == 0) {
            *(s16*)(obj + 0x7C) = 0x28;
            *(s16*)(obj + 0x7E) = 0x20;
            *(s32*)(obj + 0x24) = -*(s32*)(obj + 0x24);
        }
    }
}
