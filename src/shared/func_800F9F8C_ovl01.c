#include "types.h"
#include "mmx5/ovl01.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FD578_ovl01[];
extern u8 D_800FD57C_ovl01[];

void func_800F9F8C_ovl01(u8* arg0) {
    *(u8**)(arg0 + 0x50) = D_800FD57C_ovl01;
    *(u8**)(arg0 + 0x54) = D_800FD578_ovl01;
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[5] = 3;
        arg0[6] = 0;
    }
}

void func_800F9FCC_ovl01(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        set_animation(obj, 0);
        func_800FB308_ovl01(obj);
        obj[5] = 3;
        obj[6] = 0;
    }
}
