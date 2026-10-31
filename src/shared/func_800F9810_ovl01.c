/* Shared body (DK-5), from the banked draft of func_800F9810_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_80044DE0();
extern s32 func_80016490(s32, s32, void*);
extern void func_800FB348_ovl01(u8* obj);
extern void func_8003D2C4(void);
extern u8 D_800D1C00[];
extern u8 D_8009A1F8[];
extern u8 D_800FD578_ovl01[];
extern u8 D_80075C00[];

void DEDUP_NAME(u8* obj) {
    u8* h;
    u8* k;
    u8* g;
    u8* d;
    u8* e;

    if (func_80044DE0() == 0) {
        d = D_800D1C00;
        if ((s8)d[0xC] != 0xC) {
            h = D_8009A1F8;
            *(s16*)(h + 0x26) = 0x24D0;
        } else {
            k = D_8009A1F8;
            *(s16*)(k + 0x26) = 0x1D0;
        }
        g = D_8009A1F8;
        g[0x48] = 2;
        if (*(s16*)(obj + 0x7C) != 0) {
            *(s16*)(obj + 0x7C) -= 1;
            return;
        }
        if (--*(s16*)(obj + 0x7E) == 0) {
            func_80016490(0, 0xE, 0);
            *(s16*)(obj + 0x7E) = 3;
        }
        e = D_800D1C00;
        if ((s8)++obj[0x5C] == (s8)e[0xA2]) {
            g[0x48] = 8;
            obj[0x95] = 1;
            obj[0x89] = 0;
            *(u8**)(obj + 0x54) = D_800FD578_ovl01;
            *(u8**)(obj + 0x58) = D_80075C00;
            func_800FB348_ovl01(obj);
            obj[5] = 3;
            obj[6] = 0;
            func_8003D2C4();
        }
    }
}
