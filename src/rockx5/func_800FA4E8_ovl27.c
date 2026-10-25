#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FD700_ovl27[];
extern u8 D_800FD704_ovl27[];
extern u8 D_800FD708_ovl27[];

void func_800FA4E8_ovl27(u8* obj) {
    func_800171E8(obj, 0x13);
    *(u8**)(obj + 0x68) = D_800FD700_ovl27;
    *(u8**)(obj + 0x50) = D_800FD708_ovl27;
    *(u8**)(obj + 0x54) = D_800FD704_ovl27;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s16*)(obj + 0x7C) = 0x50;
    obj[6]++;
}
