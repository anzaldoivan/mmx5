#include "types.h"

extern void func_800F6D58_ovl00(s32);
extern s32 func_8002C218(void);
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;

void func_800F839C_ovl00(u8* arg0) {
    func_800F6D58_ovl00(0);
    func_800F6D58_ovl00(1);
    func_800F6D58_ovl00(2);
    func_800F6D58_ovl00(3);
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        D_800D50DC = 0;
        D_8009A42C = 0;
        D_80093E66 = 0;
        func_8002C218();
        arg0[6]++;
    }
}
