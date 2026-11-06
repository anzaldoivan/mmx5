#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_800FCC24_ovl38(u8* obj, s32 state);
extern void func_800FCE6C_ovl38(u8* a0);
extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];

void func_800FC0E8_ovl38(u8* arg0) {
    u8 t = arg0[0x15];

    if ((t == 0 && (arg0[0x70] & 2)) || (t == 0x40 && (arg0[0x70] & 1))) {
        func_800171E8(arg0, 3);
        *(u8**)(arg0 + 0x50) = D_800FD574_ovl38;
        *(u8**)(arg0 + 0x54) = D_800FD578_ovl38;
        *(u8**)(arg0 + 0x68) = D_800FD57C_ovl38;
        arg0[6]++;
        return;
    }
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        *(s16*)(arg0 + 0x7C) = 8;
        func_800FCC24_ovl38(arg0, 4);
    }
    func_800FCE6C_ovl38(arg0);
}
