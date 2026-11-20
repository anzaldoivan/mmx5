#include "types.h"
#include "mmx5/globals.h"

void func_800EF2C4_ovl11(u8* obj) {
    animate_object(obj);
    *(u16*)(obj + 0x80) += 1;
    if (*(s8*)(obj + 0x45) == 1) {
        obj[5] = 3;
    }
}
