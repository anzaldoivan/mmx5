#include "types.h"
#include "addr.h"

extern s32 func_8002DF78(void);

s32 func_800F37C4_ovl07(void) {
    if (!(func_8002DF78() & 7)) {
        D_1F80004C.bytes[0x84] = 1;
        return 1;
    }
    return 0;
}
