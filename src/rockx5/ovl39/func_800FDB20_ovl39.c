#include "types.h"
#include "mmx5/object.h"

void func_800FDB20_ovl39(u8* a0) {
    move_object(a0);
    if (*(s16*)(a0 + 0xE) < 0x711) {
        (*(u8**)(a0 + 0x7C))[0x89] = 3;
        *(s32*)(a0 + 0x24) = 0;
        a0[6] += 2;
    }
}
