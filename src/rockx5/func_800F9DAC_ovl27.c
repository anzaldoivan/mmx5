#include "types.h"
#include "addr.h"

extern int func_8002D6FC();
extern u8 D_800D1C00[];

void func_800F9DAC_ovl27(u8* a0) {
    u8* p;

    if (**(s8**)(D_1F80004C.bytes + 0x80) == 0) {
        p = D_800D1C00;
        p[0xF] = 0x10;
        p[0x24] = 0;
        *(s32*)(p + 0x20) = 0;
        func_8002D6FC(a0);
    }
}
