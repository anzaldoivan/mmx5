#include "types.h"

void func_800F796C_ovl09(u8* obj) {
    if (++*(u16*)(obj + 0x84) == 50) {
        obj[5] = 3;
        obj[6] = 0;
    }
}
