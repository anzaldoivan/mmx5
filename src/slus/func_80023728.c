#include "types.h"

extern Blk1BC D_800D1C00;

void func_80023728(void) {
    u8* p = 0x801F61C8;

    D_800D1C00 = *(Blk1BC*)p;
}
