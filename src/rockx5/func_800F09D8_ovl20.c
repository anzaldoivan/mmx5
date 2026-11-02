#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern void func_80028B18(s32, s32, s32, void*);
extern u8* func_8002D53C(void);
extern u8 D_80091C44;
extern s8 D_8009A298;
extern s8 D_800D1C28;
extern u8 D_800F5058_ovl20[][8];
extern s16 D_800F5108_ovl20[];
extern s32 D_800F52C4_ovl20[];
extern u16 D_800F52D4_ovl20[][2];

void func_800F09D8_ovl20(u8* arg0) {
    s32 idx;
    s32 n;
    u8* p;

    if (D_80091C44 == 0) {
        idx = ((s8*)arg0)[3];
        if (idx == 4) {
            func_8002385C(5, 0xFF, 0);
            arg0[2]++;
            return;
        }
        n = D_800F52C4_ovl20[idx];
        func_80028B18(1, D_800F5108_ovl20[n * 2], (&D_800F5108_ovl20[n * 2])[1],
                      D_800F5058_ovl20[n]);
        D_8009A298 = 1;
        D_800D1C28 = n;
        p = func_8002D53C();
        if (p != 0) {
            p[0] = 0x51;
            p[1] = 1;
            p[2] = n;
        }
        func_8002385C(D_800F52D4_ovl20[((s8*)arg0)[3]][0], 0xFF, 0);
        arg0[3]++;
    }
}
