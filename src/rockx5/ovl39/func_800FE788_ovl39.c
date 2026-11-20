#include "types.h"
#include "mmx5/globals.h"

void func_800FE788_ovl39(u8* obj) {
    u8* parent = *(u8**)(obj + 0x50);

    animate_object(obj);
    if (*(s8*)(obj + 0x5C) != 0) {
        obj[0x5C]--;
    } else {
        obj[4]++;
    }
    if (*(s8*)(parent + 4) == 2) {
        obj[4]++;
    }
}
