#include "types.h"
#include "addr.h"

void func_800FC41C_ovl39(u8* arg0) {
    u8* p;

    if (**(s8**)(D_1F80004C.bytes + 0x80) == 0) {
        p = D_1F80009C;
        p += *(s32*)p;
        arg0[6]++;
        *(u8**)(arg0 + 0x3C) = p;
    }
}
