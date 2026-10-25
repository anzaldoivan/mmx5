#include "types.h"

extern void func_80017248(u8* obj);

void func_800F7174_ovl28(u8* obj) {
    u8* parent;

    func_80017248(obj);
    parent = *(u8**)(obj + 0x50);
    if (parent[0x15] == 0) {
        *(s16*)(obj + 0xA) = *(s16*)(parent + 0xA) + 0x30;
    } else {
        *(s16*)(obj + 0xA) = *(s16*)(parent + 0xA) - 0x30;
    }
    *(s16*)(obj + 0xE) = *(s16*)(parent + 0xE) + 0x10;
    if (*(s8*)(obj + 0x45) == 1) {
        obj[4]++;
    }
}
