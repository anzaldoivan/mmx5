#include "types.h"

extern void func_800171E8(u8*, s32);
extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];

void func_800FBE60_ovl38(u8* arg0) {
    func_800171E8(arg0, 3);
    *(u8**)(arg0 + 0x50) = D_800FD574_ovl38;
    *(u8**)(arg0 + 0x54) = D_800FD578_ovl38;
    *(u8**)(arg0 + 0x68) = D_800FD57C_ovl38;
    arg0[6]++;
}
