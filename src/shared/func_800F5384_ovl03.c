/* Shared body (DK-5), from the banked draft of func_800F5384_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern u8 D_800FA0BC_ovl03[][6];

void DEDUP_NAME(u8* obj) {
    s8 st = *(s8*)(obj + 7);
    u8 st2 = obj[7];

    if (st == 2 || st == 5 || st == 8 || st == 11) {
        if (++*(s16*)(obj + 0x7C) == 100) {
            func_800171E8(obj, 1);
            obj[5] = D_800FA0BC_ovl03[obj[0x92]][obj[0x93]++];
            obj[6] = 0;
        }
    } else if (st == 0 || st == 3 || st == 6 || st == 9) {
        if (++*(s16*)(obj + 0x7C) == 0x93) {
            obj[7]++;
            obj[6] -= 2;
        }
    } else {
        if (++*(s16*)(obj + 0x7C) == 100) {
            obj[7] = st2 + 1;
            obj[6] -= 2;
        }
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
