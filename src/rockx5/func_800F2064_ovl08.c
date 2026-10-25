#include "types.h"

extern u8* func_8002D078();
extern u8 D_8009A0B4;

void func_800F2064_ovl08(u8* obj) {
    u8* child;

    child = func_8002D078();
    if (child != 0) {
        child[0] = 1;
        child[1] = 0x37;
        child[2] = 0;
        child[0x14] = D_8009A0B4;
        *(u8**)(child + 0x7C) = obj;
        *(u16*)(child + 0xA) = *(u16*)(obj + 0xA);
        *(u16*)(child + 0xE) = *(u16*)(obj + 0xE);
    }
}
