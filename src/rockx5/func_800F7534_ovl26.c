#include "types.h"

extern void func_8002DF54(u8* a0);

void func_800F7534_ovl26(u8* a0) {
    u16 v;

    func_8002DF54(a0);
    v = *(u16*)(*(u8**)(a0 + 0x7C) + 0x80);
    a0[6]++;
    *(u16*)(a0 + 0x88) = v;
}
