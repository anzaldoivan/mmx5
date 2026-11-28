#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

#define D_800F5024_ovl24 D_800F51E8_ovl24

#define func_800EFFBC_ovl24 func_800F313C_ovl24
#include "shared/func_800EFFBC_ovl24.c"
#undef func_800EFFBC_ovl24
#undef D_800F5024_ovl24

#include "shared/func_800F3178_ovl24.c"

void func_800F3200_ovl24(u8* arg0) {
    if (D_800C9320.h & 0x40) {
        play_sound(0, 0x22, 0);
        ((s32(*)())func_8002C50C)();
        arg0[0] = 0xE;
        arg0[1] = 3;
        arg0[2] = 0;
        arg0[3] = 0;
    }
}
