#include "types.h"
#include "mmx5/globals.h"

extern s8 D_8009A418;
extern u8 D_800D1F3C;
extern s32 D_800E8064;

void func_80017E54(s32 arg0) {
    if (D_800D1C0C.h == 0x10C || D_800D1F3C != 0) {
        D_800E8064 = arg0;
        D_8009A418 = 1;
    }
}
