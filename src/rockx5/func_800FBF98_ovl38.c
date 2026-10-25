#include "types.h"

extern void func_800FCAA0_ovl38(u8*);
extern void func_800171E8(u8*, s32);
extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];

void func_800FBF98_ovl38(u8* arg0) {
    func_800FCAA0_ovl38(arg0);
    *(u8**)(arg0 + 0x50) = D_800FD574_ovl38;
    *(u8**)(arg0 + 0x54) = D_800FD578_ovl38;
    *(u8**)(arg0 + 0x68) = D_800FD57C_ovl38;
    if (arg0[0x15] == 0) {
        if (*(s16*)(arg0 + 0xA) < 0x11A0) {
            func_800171E8(arg0, 3);
            arg0[6] = 3;
            return;
        }
    } else if (*(s16*)(arg0 + 0xA) > 0x1280) {
        func_800171E8(arg0, 3);
        arg0[6] = 3;
        return;
    }
    func_800171E8(arg0, 4);
    arg0[6]++;
}
