#include "types.h"
#include "mmx5/globals.h"

void func_800FD494_ovl38(u8* obj) {
    u8* parent;

    if (*(s8*)(*(u8**)(obj + 0x50) + 4) == 2) {
        obj[3] = 0;
        obj[4]++;
        return;
    }
    animate_object(obj);
    parent = *(u8**)(obj + 0x50);
    obj[3] = 1;
    *(s16*)(obj + 0xA) = *(s16*)(parent + 0xA);
    *(s16*)(obj + 0xE) = *(s16*)(parent + 0xE);
    obj[0x15] = parent[0x15];
}
