#include "types.h"
#include "addr.h"

extern s32 func_8002DF78(void);

void func_800F6C48_ovl01(void) {
    D_1F80004C.bytes[0x84] = func_8002DF78() & 3;
}
