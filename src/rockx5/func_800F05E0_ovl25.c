#include "types.h"

extern void func_80017D88(void);
extern void func_80012E0C(s32, void (*)(void));
extern void func_80012EAC(void);
extern void func_8001E534(void);
extern s8 D_8009A424;
extern u8 D_800D1F28[];
extern u8 D_800F24F4_ovl25;
extern s32 D_80091D54;

void func_800F05E0_ovl25(void) {
    if (D_8009A424 == 0) {
        D_800D1F28[0] = 3;
        D_800D1F28[1] = 0;
        D_800D1F28[2] = 0;
        D_800D1F28[3] = 0;
        D_800F24F4_ovl25 = 1;
        D_80091D54 = 0;
        func_80017D88();
        func_80012E0C(0, func_8001E534);
        func_80012EAC();
    }
}
