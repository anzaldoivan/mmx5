#include "types.h"
#include "addr.h"

extern s32 D_8009A0A8;

s32 func_800F2F8C_ovl01(u8* obj) {
    if (obj[0x15] == 0x40) {
        if (*(s32*)(obj + 8) > D_8009A0A8) {
            obj[6] = 2;
            D_1F80004C.bytes[0x80] = 0x28;
            return 1;
        }
    } else {
        if (*(s32*)(obj + 8) < D_8009A0A8) {
            obj[6] = 2;
            D_1F80004C.bytes[0x80] = 0x28;
            return 1;
        }
    }
    return 0;
}
