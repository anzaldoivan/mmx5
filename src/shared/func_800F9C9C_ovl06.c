/* Shared body (DK-5), from the banked draft of func_800F9C9C_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s32 func_8002FB58(u8* obj);
extern void func_800171E8(u8* obj, s32 n);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    func_8002FB58(obj);
    if (*(s32*)(obj + 0x24) < 0) {
        func_800171E8(obj, 0x14);
        obj[6]++;
    }
}
