#include "types.h"
#include "mmx5/globals.h"

void func_800FE680_ovl39(u8* obj) {
    u8* parent = *(u8**)(obj + 0x50);

    animate_object(obj);
    if (*(s8*)(parent + 6) >= 3 || *(s8*)(parent + 4) == 2) {
        obj[4]++;
    }
}
