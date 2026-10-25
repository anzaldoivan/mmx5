#include "types.h"
#include "addr.h"

extern s32 func_8002DF78(void);

void func_800FC8A8_ovl39(u8* a0) {
    u8* p = D_1F80004C.bytes;
    u32 r;

    p[0x88] ^= 1;
    r = func_8002DF78();
    *(s16*)(a0 + 0x7E) = 0x18;
    a0[6]++;
    *(s16*)(a0 + 0x7C) = (u8)(r % 7) * 10 + 60;
}
