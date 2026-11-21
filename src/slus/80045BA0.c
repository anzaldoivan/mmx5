#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define D_800F4844_ovl05 D_80076EBC

#define func_800EEA80_ovl05 func_80045BA0
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern u8 D_80076E70[];

void func_80045BDC(u8* obj) {
    u8* p = g_Player;

    if (*(s8*)(p + 5) != 0x25) {
        clear_object_slot(obj);
    }
    if (*(s8*)(obj + 4) == 0) {
        obj[4]++;
        obj[3] = 0;
        obj[0x64] = 1;
        *(u8**)(obj + 0x50) = D_80076E70;
        obj[0x15] = 0;
        obj[0x98] = 0;
        *(u32*)(obj + 0x8C) = 0;
        if (p[0x15] != 0) {
            *(u16*)(obj + 0xA) = *(u16*)(p + 0xA) + 0x16;
        } else {
            *(u16*)(obj + 0xA) = *(u16*)(p + 0xA) - 0x16;
        }
        *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
        return;
    }
    if (*(s8*)(p + 0x45) == 0) {
        clear_object_slot(obj);
        return;
    }
    if (!(D_8009A420_as_s32 & 3)) {
        obj[0x64]++;
    }
    if (*(s8*)(obj + 0x98) != 0) {
        obj[0x98] = 0;
        if (++*(u32*)(obj + 0x8C) >= 8) {
            clear_object_slot(obj);
        }
    }
}
#undef D_8009A420_as_s32

#define D_800F4844_ovl05 D_80076EA0

#define func_800EEA80_ovl05 func_80045D08
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
