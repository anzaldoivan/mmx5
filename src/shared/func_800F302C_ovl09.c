/* Shared body (DK-5), from the banked draft of func_800F302C_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002DF78(void);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern signed char D_800D1CA2;
extern u8 D_800FABA0_ovl09[];

void DEDUP_NAME(u8* obj) {
    s32 v;
    s32 r;

    if (++*(s16*)(obj + 0x7C) == 40) {
        *(u8**)(obj + 0x50) = D_800FABA0_ovl09;
        func_800171E8(obj, 4);
        if (D_800D1CA2 / 2 < *(s8*)(obj + 0x5C)) {
            v = obj[0x15];
            if (v == 0) {
                v = -0x20000;
            } else {
                v = 0x20000;
            }
        } else {
            v = obj[0x15];
            if (v == 0) {
                v = -0x40000;
            } else {
                v = 0x40000;
            }
        }
        *(s32*)(obj + 0x20) = v;
        r = func_8002DF78();
        obj[0x91] = 99;
        *(s16*)(obj + 0x7E) = 0;
        obj[6]++;
        *(s16*)(obj + 0x7C) = (r % 5 + 3) * 10;
    }
    if (*(u16*)(obj + 0x7C) & 1) {
        func_8002D9EC(obj, 0x40, 0x40);
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
