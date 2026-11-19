#include "types.h"
#include "addr.h"

void func_800F880C_ovl09(u8* a0) {
    if (D_1F80004C.bytes[0x85] == 7) {
        D_1F80004C.bytes[0x85] = 0xFF;
    }
    if (D_1F80004C.bytes[0x84] == 7) {
        D_1F80004C.bytes[0x85] = 0;
        D_1F80004C.bytes[0x84] = 0;
        a0[6]++;
    }
}
