#include "types.h"
#include "mmx5/globals.h"

void func_800FEA5C_ovl07(u8* obj) {
    if (*(s8*)(obj + 0x45) == 6) {
        obj[4] = 2;
        return;
    }
    if (*(s8*)(obj + 2) == 5) {
        *(u16*)(obj + 0xA) -= 0x10;
    } else {
        *(u16*)(obj + 0xA) += 0x10;
    }
    animate_object(obj);
}
