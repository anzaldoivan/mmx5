#include "types.h"
#include "mmx5/globals.h"

void func_800F6238_ovl26(u8* obj) {
    animate_object(obj);
    if ((*(u8**)(obj + 0x7C))[0x93] == 0) {
        obj[4] = 2;
    }
}
