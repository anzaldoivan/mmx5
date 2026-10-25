#include "types.h"

extern void func_8002DF54(u8* a0);

void func_800FDB20_ovl39(u8* a0) {
    func_8002DF54(a0);
    if (*(s16*)(a0 + 0xE) < 0x711) {
        (*(u8**)(a0 + 0x7C))[0x89] = 3;
        *(s32*)(a0 + 0x24) = 0;
        a0[6] += 2;
    }
}
