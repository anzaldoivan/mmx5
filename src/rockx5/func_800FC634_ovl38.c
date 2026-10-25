#include "types.h"

extern void func_800171E8(u8*, s32);
extern void func_80016490(s32, s32, void*);
extern void func_800FCAA0_ovl38(u8*);
extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];

void func_800FC634_ovl38(u8* arg0) {
    func_800171E8(arg0, 0x14);
    func_80016490(2, 0xA3, arg0);
    *(u8**)(arg0 + 0x50) = D_800FD574_ovl38;
    *(u8**)(arg0 + 0x54) = D_800FD578_ovl38;
    *(u8**)(arg0 + 0x68) = D_800FD57C_ovl38;
    func_800FCAA0_ovl38(arg0);
    arg0[6]++;
}
