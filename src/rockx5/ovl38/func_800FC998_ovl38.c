#include "types.h"
#include "mmx5/graphics.h"

extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];

void func_800FC998_ovl38(u8* arg0) {
    set_animation(arg0, 0xD);
    *(u8**)(arg0 + 0x50) = D_800FD574_ovl38;
    *(u8**)(arg0 + 0x54) = D_800FD578_ovl38;
    *(u8**)(arg0 + 0x68) = D_800FD57C_ovl38;
    arg0[6]++;
}
