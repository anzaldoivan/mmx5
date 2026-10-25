#include "types.h"

void func_800171E8(void* self, s32 arg1);

void func_800F0810_ovl29(u8* self) {
    *(s32*)(self + 0x20) = 0;
    *(s32*)(self + 0x28) = 0;
    *(s32*)(self + 0x24) = 0;
    *(s32*)(self + 0x2C) = 0;
    func_800171E8(self, 0x14);
    self[6]++;
}
