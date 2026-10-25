#include "types.h"

extern s8 D_8009A424;
extern u8 D_800D1C00[];
extern void func_8002C50C(void);
extern void func_8002002C(s32);
extern void func_80012E0C(s32, void (*)(void));
extern void func_80012EAC(void);
extern void func_80020904(void);

void func_8001DCC8(u8* a0) {
    if (D_8009A424 == 0) {
        func_8002C50C();
        func_8002002C(1);
        if (a0[0x194] == 0xFF) {
            D_800D1C00[0] = 3;
            D_800D1C00[1] = 0;
            D_800D1C00[2] = 0;
            D_800D1C00[3] = 0;
        } else {
            u8* p = D_800D1C00;
            u8 v = p[0x194];
            p[0] = 0x13;
            p[1] = 0;
            p[2] = 0;
            p[3] = 0;
            p[0x1D] = v;
        }
        func_80012E0C(1, func_80020904);
        func_80012EAC();
    }
}
