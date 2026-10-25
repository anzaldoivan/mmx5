#include "types.h"

extern void (*D_800F5904_ovl20[])(u8*);
extern u8 D_800D1C00[];
extern int func_8002D6FC();

void func_800F41F0_ovl20(u8* arg0) {
    D_800F5904_ovl20[((s8*)arg0)[4]](arg0);
    arg0[0x54] = D_800D1C00[0x2A];
    if (((s8*)D_800D1C00)[0x31] != 0) {
        func_8002D6FC(arg0);
    }
}
