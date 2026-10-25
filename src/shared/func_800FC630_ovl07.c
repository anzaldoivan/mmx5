/* Shared body (DK-5), from the banked draft of func_800FC630_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

#include "addr.h"
extern void func_80017248(u8* obj);
extern void func_800FCAD8_ovl07(u8* obj, s16 x, s16 y, s32 kind, s32 arg4);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if (*(signed char*)(obj + 0x45) == 1) {
        if (D_1F80004C.bytes[0x90] == 2) {
            func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 8,
                                0);
        } else {
            func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 7,
                                0);
        }
        *(s16*)(obj + 0x7C) = 0x3C;
        obj[6]++;
    }
}
