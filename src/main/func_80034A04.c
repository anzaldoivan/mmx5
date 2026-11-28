#include "types.h"
#include "mmx5/object.h"

extern void (*D_8007338C[])(u8*);

void func_80034A04(void) {
    u8* slot = D_800D4F40.u;

    D_8007338C[(s8)slot[4]](slot);
}
