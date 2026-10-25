#include "types.h"

extern void func_8001A028(s32);
extern s32 D_800D1F38;

void func_8001E810(u8* arg0) {
    arg0[0xD] = 1;
    D_800D1F38 = 0x80105000;
    func_8001A028(1);
    arg0[1]++;
}
