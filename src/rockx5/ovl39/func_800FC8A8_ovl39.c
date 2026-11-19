#include "types.h"
#include "mmx5/system.h"
#include "addr.h"

void func_800FC8A8_ovl39(u8* a0) {
    u8* p = D_1F80004C.bytes;
    u32 r;

    p[0x88] ^= 1;
    r = random_byte();
    *(s16*)(a0 + 0x7E) = 0x18;
    a0[6]++;
    *(s16*)(a0 + 0x7C) = (u8)(r % 7) * 10 + 60;
}
