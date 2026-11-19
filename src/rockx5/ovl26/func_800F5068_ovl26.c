#include "types.h"
#include "mmx5/globals.h"

void func_800F5068_ovl26(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 7) == 0x20) {
        *(s16*)(obj + 0x7C) = 0x78;
        obj[6]++;
    }
}
