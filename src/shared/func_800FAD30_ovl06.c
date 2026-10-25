/* Shared body (DK-5), from the banked draft of func_800FAD30_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DED4(u8* obj);
extern s32 func_8002FB58(u8* obj);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    func_8002DED4(obj);
    func_8002FB58(obj);
    func_80017248(obj);
    if (obj[0x70] & 4) {
        func_800171E8(obj, 5);
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0x1000;
        obj[6]++;
    }
}
