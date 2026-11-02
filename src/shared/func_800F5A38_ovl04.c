/* Shared body (DK-5), from the banked draft of func_800F5A38_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002DF78(void);

void DEDUP_NAME(u8* obj) {
    obj[0x8A] = 0x3C;
    func_800171E8(obj, 3);
    obj[4] = 1;
    obj[7] = 0;
    if (*(s8*)(obj + 5) != 2) {
        obj[0x91] = func_8002DF78() & 0xF;
        if (obj[0x91] < 5) {
            obj[0x91] = 0;
        } else if (obj[0x91] < 8) {
            obj[0x91] = 1;
        } else if (obj[0x91] < 11) {
            obj[0x91] = 2;
        } else {
            obj[0x91] = 3;
        }
        *(s8*)(obj + 0x90) = -1;
        obj[0x92] = 0;
        obj[0x8D] = 0;
        obj[0x8F] = 0;
        *(s16*)(obj + 0x7E) = 0x250;
        obj[5] = 4;
        obj[6] = 0;
        return;
    }
    if (*(s8*)(obj + 6) >= 4) {
        obj[6] = 3;
    }
}
