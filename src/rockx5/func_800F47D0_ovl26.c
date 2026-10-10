#include "types.h"

#define D_1F80004C (*(u8**)0x1F80004C)

extern void func_80017248(u8* obj);

void func_800F47D0_ovl26(u8* obj) {
    func_80017248(obj);
    if (D_1F80004C[0x92] == 0) {
        obj[5] = 4;
        obj[6] = 0;
    }
}
