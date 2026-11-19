#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/system.h"
#include "addr.h"

s32 func_800F37C4_ovl07(void) {
    if (!(random_byte() & 7)) {
        D_1F80004C.bytes[0x84] = 1;
        return 1;
    }
    return 0;
}
