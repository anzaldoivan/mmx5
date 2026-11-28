#include "types.h"
#include "addr.h"

extern u16* D_800A51A0;

void func_80017768(void) {
    u16* src = (u16*)D_1F800008;
    u16* dst = D_800A51A0;
    s32 count = (u32)(D_1F80000C - D_1F800008) >> 1;

    while (count > 0) {
        *dst++ = *src++;
        count--;
    }
}
