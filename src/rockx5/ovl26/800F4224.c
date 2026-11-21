#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/system.h"
#include "addr.h"

void func_800F4224_ovl26(u8* obj) {
    set_animation(obj, 0x19);
    animate_object(obj);
    obj[6]++;
}

extern u8 D_800F9628_ovl26[];

void func_800F4260_ovl26(u8* obj) {
    animate_object(obj);
    if (((s8*)obj)[0x45] == 1) {
        *(s32*)(obj + 0x54) = 0;
        *(u8**)(obj + 0x50) = D_800F9628_ovl26;
        set_animation(obj, 7);
        *(s32*)(obj + 0x24) = 0x40000;
        obj[6]++;
    }
}

void func_800F42C0_ovl26(u8* obj) {
    move_object(obj);
    animate_object(obj);
    if (*(s16*)(obj + 0xE) < 0x123D) {
        *(s32*)(obj + 0x24) = 0;
        obj[6]++;
        set_animation(obj, 0xF);
    }
}

void func_800F4318_ovl26(u8* obj) {
    u8* scr;

    animate_object(obj);
    if (obj[0x47] == 0x31) {
        scr = D_1F80004C.bytes;
        if (scr[0x93] != 0) {
            scr[0x93] = 0;
        }
    }
    if (((s8*)obj)[0x45] == 1) {
        obj[5] = (((s8*)obj)[0x5C] >= D_800D1CA2 / 2 ||
                  (u32)(random_byte() & 0xF) < 8)
                     ? 5
                     : 10;
        obj[6] = 0;
    }
}

#define D_8007BD4C D_800FA13C_ovl26

#define func_800532E0 func_800F43C8_ovl26
#include "shared/func_800532E0.c"
#undef func_800532E0
