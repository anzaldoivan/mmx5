/* Shared body (DK-5), from the banked draft of func_800FBBAC_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);
extern void func_80017248(u8* obj);

void DEDUP_NAME(u8* obj) {
    if (*(s8*)(obj + 0x45) != 0) {
        func_800171E8(obj, 2);
        D_1F80004C.bytes[0x92] = 1;
        func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 2);
        obj[0x15] = 0;
        *(s16*)(obj + 0x7C) = 6;
        *(s16*)(obj + 0x7E) = 0;
        obj[6]++;
    }
    func_80017248(obj);
}
