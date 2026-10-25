#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern u8 D_800D1C2A;

void func_800FFD68_ovl04(u8* self) {
    u8* parent;

    func_80017248(self);
    if (*(s8*)(self + 0x45) == 1) {
        func_800317B8(self);
    }
    parent = *(u8**)(self + 0x7C);
    *(s16*)(self + 0xA) = *(s16*)(parent + 0xA) + 0x30;
    *(s16*)(self + 0xE) = *(s16*)(parent + 0xE);
    if (((s8*)&D_800D1C2A)[1] == 0) {
        self[4]++;
    }
    self[3] = 1;
}
