#include "types.h"

extern void func_80017248(u8* obj);

void func_800FD494_ovl38(u8* obj) {
    u8* parent;

    if (*(s8*)(*(u8**)(obj + 0x50) + 4) == 2) {
        obj[3] = 0;
        obj[4]++;
        return;
    }
    func_80017248(obj);
    parent = *(u8**)(obj + 0x50);
    obj[3] = 1;
    *(s16*)(obj + 0xA) = *(s16*)(parent + 0xA);
    *(s16*)(obj + 0xE) = *(s16*)(parent + 0xE);
    obj[0x15] = parent[0x15];
}
