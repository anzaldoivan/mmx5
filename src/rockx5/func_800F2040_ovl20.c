#include "types.h"

extern int func_8002D6FC();

void func_800F2040_ovl20(u8* obj) {
    u8* parent = *(u8**)(obj + 0x50);

    *(u16*)(obj + 0xA) = *(u16*)(parent + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(parent + 0xE);
    obj[3] = parent[3];
    if (((s8*)parent)[4] >= 3) {
        func_8002D6FC(obj);
    }
}
