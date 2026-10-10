/* Shared body (DK-5), from the banked draft of func_800FAC64_ovl54 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800D1F3C;
extern signed char D_8009A424;
extern u8 D_8009A1F8[];
extern u8 D_800D1C00[];
extern void func_8001E668(void);
extern void func_8002C50C(void);

void DEDUP_NAME(u8* arg0) {
    s32 i;
    u8* p;

    if (D_800D1F3C == 0 && D_8009A424 == 0) {
        func_8001E668();
        D_8009A1F8[0x3] = 0;
        D_8009A1F8[0x57] = 0;
        D_8009A1F8[0xAB] = 0;
        func_8002C50C();
        i = 15;
        p = arg0 + 0x35;
        for (; i >= 0; i--) {
            *p-- = 0;
        }
        arg0[0xC] = 0x12;
        arg0[0xD] = 0;
        D_800D1C00[0x27] = 0;
        arg0[0] = 0xB;
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
    }
}
