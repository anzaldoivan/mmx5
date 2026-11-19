#include "types.h"
#include "mmx5/globals.h"

void func_800FE35C_ovl39(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 0x10) {
        *(*(u8**)(obj + 0x7C) + 0x8B) = 1;
        obj[4] = 2;
    }
}
