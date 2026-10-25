#include "types.h"

extern void (*D_800F582C_ovl20[])(u8*);
extern s8 D_800D1C01;
extern int func_8002D6FC();

void func_800F3CD8_ovl20(u8* arg0) {
    D_800F582C_ovl20[(s8)arg0[4]](arg0);
    if (D_800D1C01 != 6) {
        func_8002D6FC(arg0);
    }
}
