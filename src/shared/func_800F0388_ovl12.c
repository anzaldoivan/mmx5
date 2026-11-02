/* Shared body (DK-5), from the banked draft of func_800F0388_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern u8* func_8002D1A4();

void DEDUP_NAME(u8* arg0) {
    u8* obj;

    if (--*(s16*)(arg0 + 0x7C) == -1) {
        obj = func_8002D1A4();
        if (obj != 0) {
            func_80016490(2, 0x37, arg0);
            func_80016490(2, 0x41, arg0);
            obj[0] = 0x41;
            obj[1] = 0x18;
            obj[2] = 1;
            *(u8**)(obj + 0x7C) = arg0;
        }
        if (*(s8*)(arg0 + 2) == 0) {
            arg0[6]++;
        }
        if (*(s16*)(arg0 + 0x7E) != 0) {
            arg0[6]++;
        }
        *(s16*)(arg0 + 0x7C) = 0x3C;
        (*(s16*)(arg0 + 0x7E))++;
    }
}
