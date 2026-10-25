/* Shared body (DK-5), from the banked draft of func_800F4F54_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DED4(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern int func_8002D6FC();

void DEDUP_NAME(u8* obj) {
    func_8002DED4(obj);
    if (func_8002D938(obj, 0x40, 0x40) == 0) {
        if (obj[7] ^= 1) {
            func_8002D9EC(obj, 0x20, 0x20);
        } else {
            obj[3] = 0;
        }
    } else {
        func_8002D6FC(obj);
    }
}
