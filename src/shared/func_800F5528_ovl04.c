/* Shared body (DK-5), from the banked draft of func_800F5528_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* o, s32 n);
extern void func_80017248(u8* o);
extern s32 func_8002DF78(void);

void DEDUP_NAME(u8* o) {
    s32 base;

    if (--*(s16*)(o + 0x7C) == 0) {
        o[5] = 5;
        *(s8*)(o + 0x90) *= -1;
        o[0x8F] ^= 1;
        if (o[0x8F] == 0) {
            func_800171E8(o, 3);
            base = 0;
            o[5] = 4;
            o[6] = 0;
        } else {
            base = 4;
        }
        o[0x91] = func_8002DF78() & 0xF;
        if (o[0x91] < 5) {
            o[0x91] = base;
        } else if (o[0x91] < 8) {
            o[0x91] = base + 1;
        } else if (o[0x91] < 11) {
            o[0x91] = base + 2;
        } else {
            o[0x91] = base + 3;
        }
    }
    func_80017248(o);
}
