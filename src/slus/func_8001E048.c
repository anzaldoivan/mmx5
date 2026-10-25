#include "types.h"

extern void SetDispMask(s32);
extern void func_80013B8C(void);
extern void func_80016CD0(void);
extern void func_8001E0D0(void);
extern void func_80012F58(void (*)(void));
extern void func_8001E534(void);
extern u8 D_800D1F28[];
extern s32 D_80091D54;

void func_8001E048(void) {
    u8* p;
    s32 i;
    u8 z;

    SetDispMask(0);
    func_80013B8C();
    func_80016CD0();
    func_8001E0D0();
    z = 0;
    p = D_800D1F28;
    i = 15;
    do {
        *p++ = z;
    } while (i-- != 0);
    D_80091D54 = 0;
    D_800D1F28[0] = 0;
    D_800D1F28[1] = 0;
    D_800D1F28[2] = 0;
    D_800D1F28[3] = 0;
    func_80012F58(func_8001E534);
}
