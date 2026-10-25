/* Shared body (DK-5), from the banked draft of func_800F3A80_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_8002D800(u8* a0);
extern void func_8002DED4(u8* obj);
extern void func_80017248(u8* obj);
extern void func_8002D89C(u8*);
extern void func_8002D6FC(u8* obj);

void DEDUP_NAME(u8* obj) {
    if (func_8002D800(obj) == 0) {
        func_8002DED4(obj);
        func_80017248(obj);
        obj[3] ^= 1;
        if (obj[3] != 0) {
            func_8002D89C(obj);
        }
    } else {
        func_8002D6FC(obj);
    }
}
