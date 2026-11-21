#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

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

void func_800FFF18_ovl04(u8* a0) {
    u8* p = *(u8**)(a0 + 0x50);

    *(s32*)(a0 + 0x8) = *(s32*)(p + 0x18);
    *(s32*)(a0 + 0xC) = *(s32*)(p + 0x1C);
    a0[0x47] = p[0x47];
    if (*(s8*)(p + 4) >= 2) {
        a0[4]++;
    }
    if (a0[2] & 1) {
        func_8002D9EC(a0, 0x10, 0x10);
    } else {
        a0[3] = 0;
    }
}

#define D_800EEBA0_ovl00 func_800FFFB0_ovl04
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
