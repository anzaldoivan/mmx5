#include "types.h"

extern s8 D_8009A418;
extern u16 D_800D1C0C;
extern u8 D_800D1F3C;
extern s32 D_800E8064;

void func_80017E54(s32 arg0) {
    if (D_800D1C0C == 0x10C || D_800D1F3C != 0) {
        D_800E8064 = arg0;
        D_8009A418 = 1;
    }
}
