#include "types.h"

extern u8 D_800D4F40[];
extern void (*D_8007338C[])(u8*);

void func_80034A04(void) {
    u8* slot = D_800D4F40;

    D_8007338C[(s8)slot[4]](slot);
}
