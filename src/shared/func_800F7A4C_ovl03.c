/* Shared body (DK-5), from the banked draft of func_800F7A4C_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_8002DF78(void);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern signed char D_800D1CA2;
extern u8 D_800FA0BC_ovl03[][6];

void DEDUP_NAME(u8* arg0) {
    u32 r;

    r = func_8002DF78() & 0xF;
    arg0[0x93] = 0;
    if (D_800D1CA2 / 2 < (s8)arg0[0x5C]) {
        if (r < 12) {
            arg0[0x92] = 0;
        } else {
            arg0[0x92] = 1;
        }
    } else if (r < 6) {
        arg0[0x92] = 2;
    } else if (r < 12) {
        arg0[0x92] = 3;
    } else if (r >= 14) {
        arg0[0x92] = 5;
    } else {
        arg0[0x92] = 4;
    }
    arg0[5] = D_800FA0BC_ovl03[arg0[0x92]][arg0[0x93]++];
    arg0[6] = 0;
    func_80017248(arg0);
    func_8002DED4(arg0);
    func_8002D9EC(arg0, 0xFF, 0xFF);
}
