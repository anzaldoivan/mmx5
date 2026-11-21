#include "types.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

extern u8 D_800FD604_ovl01[];
extern u8 D_800FD600_ovl01[];
extern u8 D_800FD608_ovl01[];

void func_800FAFDC_ovl01(u8* arg0) {
    set_animation(arg0, 3);
    *(u8**)(arg0 + 0x50) = D_800FD604_ovl01;
    *(u8**)(arg0 + 0x54) = D_800FD600_ovl01;
    *(s32*)(arg0 + 0x24) = 0x20000;
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0x1000;
    *(u8**)(arg0 + 0x68) = D_800FD608_ovl01;
    move_object(arg0);
    arg0[6] = 1;
}
