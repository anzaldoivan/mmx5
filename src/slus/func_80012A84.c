#include "types.h"

extern void SetDispMask(s32);
extern s32 func_80012F00(s32);
extern void func_80016384(void);
extern void func_8001E668(void);
extern void func_8001E6AC(void);
extern void func_8002CF20(void);
extern s32 D_8006FB14;
extern s32 D_8006FC24;
extern s8 D_8006FC28;
extern s32 D_80091D54;
extern u16 D_8009A41A;
extern s8 D_8009A424;
extern u16 D_800C931C;
extern s8 D_800E9300;

void func_80012A84(void) {
    s32 t;

    if (D_80091D54 != 0 && D_8009A424 == 0) {
        if ((D_800C931C & 0x900) == 0x900) {
            t = D_8009A41A - 1;
            D_8009A41A = t;
            if ((t << 16) == 0) {
                D_8006FB14 = 0;
                D_8006FC24 = 0;
                D_8006FC28 = 0;
                D_80091D54 = 0;
                D_800E9300 = 0;
                SetDispMask(0);
                func_80012F00(0);
                func_80012F00(1);
                func_80012F00(2);
                func_80012F00(3);
                D_8009A41A = 60;
                func_8001E668();
                func_80016384();
                func_8002CF20();
                func_8001E6AC();
            }
        } else {
            D_8009A41A = 60;
        }
    }
}
