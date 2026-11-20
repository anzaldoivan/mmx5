#include "types.h"
#include "addr.h"

extern s32 func_800F2224_ovl04(u8* arg0);
extern void (*D_80101690_ovl04[])(u8*);

void func_800F289C_ovl04(u8* arg0) {
    if (func_800F2224_ovl04(arg0)) {
        arg0[0x62] = 0;
        D_1F80004C.bytes[0x84] = 0;
        arg0[0x60] = 4;
        arg0[5] = 2;
        arg0[6] = 0;
    } else {
        D_80101690_ovl04[((s8*)arg0)[6]](arg0);
    }
}
