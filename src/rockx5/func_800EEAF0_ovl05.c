#include "types.h"

extern void func_80028B18(s32, s32, s32, void*);
extern int func_8002D760();
extern s32 func_8002D800(u8* a0);
extern s16 D_8009A0AE;
extern u8 D_8009A1F8[];
extern s8 D_800D1C1D;
extern s32 D_800E92F8;

void func_800EEAF0_ovl05(u8* arg0) {
    u8* d;
    u8* p;
    s16 y;

    if (func_8002D800(arg0) == 0) {
        d = D_8009A1F8;
        p = *(u8**)(arg0 + 0x18);
        y = *(s16*)(p + 0xC);
        if (*(s16*)(d + 0xE) >= y && D_8009A0AE >= y + 0x24) {
            func_80028B18(0, *(s16*)(p + 0), *(s16*)(p + 2), p + 4);
            if (*(s8*)(arg0 + 2) == 0) {
                *(s16*)(d + 0x2A) = *(s16*)(*(u8**)(arg0 + 0x18) + 0xC);
                *(s16*)(d + 0x28) = *(s16*)(*(u8**)(arg0 + 0x18) + 0xC);
                D_800E92F8 = 1;
                D_800D1C1D = 1;
                return;
            }
            arg0[4]++;
        }
    } else {
        func_8002D760(arg0);
    }
}
