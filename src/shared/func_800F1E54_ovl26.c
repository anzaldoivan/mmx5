#include "types.h"
#include "addr.h"

void func_800F1E54_ovl26(u8* obj) {
    (*(u16*)(obj + 0x7C))++;
    if (*(u16*)(obj + 0x7C) & 1) {
        obj[3] = 0;
    } else {
        obj[3] = 1;
    }
    if (*(signed char*)(obj + 0x45) != 0) {
        if (D_1F80004C.bytes[0x86] >= 2) {
            obj[3] = 0;
            obj[4] = 3;
        } else {
            obj[3] = 0;
            obj[5] = 3;
            obj[6] = 0;
        }
    }
}
