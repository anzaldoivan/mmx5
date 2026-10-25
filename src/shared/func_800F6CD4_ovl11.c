/* Shared body (DK-5), from the banked draft of func_800F6CD4_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern u8 D_800D1C00[];
extern signed char D_8009A0A5;
extern u8 D_8009A1F8[];
extern u8 D_800FA064_ovl11[];
extern void func_8003D29C(s32, s32);
extern u8* func_8002D144(void);

void DEDUP_NAME(u8* obj) {
    u8* g = D_800D1C00;
    u8* child;

    if (((signed char*)g)[0xF] == 0 && D_8009A0A5 == 0x14) {
        D_8009A1F8[0x47] = 2;
        D_800FA064_ovl11[2] = D_8009A1F8[0x48];
        if (((signed char*)g)[0xC] != 0xC) {
            g[0x27] = 1;
            func_8003D29C(0x1D, 0x40);
        }
        child = func_8002D144();
        if (child != 0) {
            child[0] = 1;
            child[1] = 0x18;
            *(u8**)(D_1F80004C.bytes + 0x84) = child;
        }
        *(s16*)(obj + 0x7C) = 0xF0;
        obj[6]++;
    }
}
