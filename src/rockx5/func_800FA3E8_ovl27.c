#include "types.h"
#include "addr.h"

void func_800FA3E8_ovl27(u8* arg0) {
    u8* p = *(u8**)(D_1F80004C.bytes + 0x80);

    if ((u32)(p[0x89] - 1) < 2) {
        u8 v = p[0x87];
        *(s16*)(arg0 + 0x7E) = 0x2A8;
        arg0[5] = 4;
        arg0[6] = 0;
        arg0[0x5C] = v;
    }
}
