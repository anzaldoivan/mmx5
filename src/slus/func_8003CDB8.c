#include "types.h"

extern u16 D_800C931C[];
extern u8 D_8009A0A0[];
u16 func_8003D688(u16 mask);

void func_8003CDB8(void) {
    u8* dst = D_8009A0A0;
    u16* src = D_800C931C;

    *(u16*)(dst + 0x7C) = func_8003D688(src[0]);
    *(u16*)(dst + 0x7E) = func_8003D688(src[1]);
    *(u16*)(dst + 0x80) = func_8003D688(src[2]);
}
