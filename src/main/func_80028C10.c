#include "types.h"

void func_80028F1C(s32 arg0, s32 x, s32 y);

void func_80028C10(s32 arg0, s16 arg1, s16 arg2, u8* arg3) {
    s32 x;
    s32 y;
    s32 i;
    s32 j;

    y = arg2;
    for (j = 0; j < *(u16*)(arg3 + 6); y += 0x10) {
        x = arg1;
        for (i = 0; i < *(u16*)(arg3 + 4); x += 0x10) {
            func_80028F1C(arg0, x, y);
            i++;
        }
        j++;
    }
}
