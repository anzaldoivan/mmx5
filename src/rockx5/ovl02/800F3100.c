#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#define func_800EFAAC_ovl03 func_800F3100_ovl02
#include "shared/func_800EFAAC_ovl03.c"
#undef func_800EFAAC_ovl03

#define func_800EEF2C_ovl18 func_800F312C_ovl02
#include "shared/func_800EEF2C_ovl18.c"
#undef func_800EEF2C_ovl18

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern u8 D_800F47B8_ovl02[];
extern u8 D_800F47BC_ovl02[];
extern u8 D_800F47C0_ovl02[];

void func_800F3158_ovl02(u8* obj) {
    animate_object(obj);
    if (((s8*)obj)[0x46] == 0) {
        set_animation(obj, 1);
        obj[5] = 3;
        obj[6] = 0;
        func_8002D9EC(obj, 0x20, 0x20);
        *(u8**)(obj + 0x68) = D_800F47C0_ovl02;
        *(u8**)(obj + 0x54) = D_800F47BC_ovl02;
        *(u8**)(obj + 0x50) = D_800F47B8_ovl02;
    } else if (D_8009A420_as_s32 & 1) {
        obj[3] = 0;
    } else {
        func_8002D9EC(obj, 0x20, 0x20);
    }
}
