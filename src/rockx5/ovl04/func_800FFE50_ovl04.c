#include "types.h"

extern u8* func_8002D33C(u8* p, s32 backward);

void func_800FFE50_ovl04(u8* self) {
    u8* parent = *(u8**)(self + 0x50);
    u8* child;

    *(u16*)(self + 0x42) = *(u16*)(parent + 0x42) & 0x7FFF;
    *(s32*)(self + 0x30) = *(s32*)(parent + 0x30);
    *(s32*)(self + 0x3C) = *(s32*)(parent + 0x3C);
    *(u16*)(self + 0x40) = *(u16*)(parent + 0x40);
    self[0x14] = 0;
    self[0x16] = 1;
    *(u16*)(self + 0xA) = *(u16*)(parent + 0xA);
    *(u16*)(self + 0xE) = *(u16*)(parent + 0xE);
    if (((s8*)self)[2] < 7) {
        child = func_8002D33C(self, 0);
        if (child != 0) {
            *(u8**)(child + 0x50) = self;
            child[0] = 0x41;
            child[1] = 0xB;
            child[2] = self[2] + 1;
        }
    }
    self[4]++;
}
