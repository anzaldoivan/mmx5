#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"

void func_80040EF0(u8* p) {
    if (*(s8*)(p + 0x45) != 0) {
        p[0x45] &= 0x7F;
        if (*(s32*)(p + 0x20) != 0) {
            *(s32*)(p + 0x28) = -0x2000;
        }
        *(s32*)(p + 0x24) = 0x2C000;
        *(s32*)(p + 0x2C) = *(s32*)(p + 0x110);
        p[6]++;
    }
}

extern void func_800392E4();
#define D_800EEBA0_ovl00 func_80040F44
#define func_8002D720 func_800392E4
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern void func_800392E4();
#define D_800EEBA0_ovl00 func_80040F64
#define func_8002D720 func_800392E4
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern void func_8003A9AC(void);
extern void player_set_animation_shooting(u8* arg0, s32 arg1);

void func_80040F84(u8* obj) {
    if (obj[0x89] & 8) {
        func_8003A9AC();
        return;
    }
    apply_object_motion(obj);
    if (*(signed char*)(obj + 0x46) == 0) {
        player_set_animation_shooting(obj, 0xB);
        obj[5] = 7;
        obj[6] = 0;
    }
}
