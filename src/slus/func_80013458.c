#include "types.h"

extern void func_80014684(s32, s32, s32);
extern void func_8001551C(s32, s32);
extern void func_80013E14(void);
extern void func_80016B64(void);
extern u8 D_800D1C00[];
extern s32 D_800BE9A8;
extern s32 D_800D1F38;
extern s32 D_8009E790;
extern s32 D_800C9314;

void func_80013458(void) {
    u8* p = D_800D1C00;
    u8 t;

    if (((s8*)p)[0x44] == 0) {
        t = p[0x49];
        if (t == 4) {
            func_80014684(0x5D, 0, 0);
        } else if (t == 2) {
            func_80014684(0x5E, 0, 0);
        } else if (t == 3) {
            func_80014684(0x5F, 0, 0);
        } else {
            if (t == 1) {
                func_80014684(0x5C, 0, 0);
            } else {
                func_80014684(0x58, 0, 0);
            }
        }
    } else {
        func_80014684(0x5A, 0, 0);
    }
    func_8001551C(0, 0);
    func_80013E14();
    D_800D1F38 = D_800BE9A8;
    D_800C9314 = D_8009E790;
    func_80016B64();
}
