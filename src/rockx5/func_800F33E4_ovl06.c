#include "types.h"

extern int func_8002D6FC();

void func_800F33E4_ovl06(u8* obj) {
    u8* p = *(u8**)(obj + 0x7C);

    p[0x7F] ^= 1 << ((s8*)obj)[2];
    func_8002D6FC(obj);
}
