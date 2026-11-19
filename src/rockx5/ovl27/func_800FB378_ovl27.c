#include "types.h"
#include "addr.h"

void func_800FB378_ovl27(u8* self) {
    s8 v = ((s8*)self)[2];

    if (v == 0) {
        self[5] = D_1F80004C.bytes[0x8D];
    } else if (v >= 0) {
        if (v < 5) {
            self[5] = D_1F80004C.bytes[0x8C];
        }
    }
}
