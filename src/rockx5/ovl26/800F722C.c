#include "types.h"
#include "mmx5/sound.h"

#define D_8007BD4C D_800FA49C_ovl26

#define func_800532E0 func_800F722C_ovl26
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

extern void func_800F72C0_ovl26(void*, u8);

void func_800F7268_ovl26(u8* arg0) {
    func_800F72C0_ovl26(arg0, ((s8*)arg0)[2] * 2);
    play_sound(2, 0x5C, arg0);
    arg0[6]++;
}

#define D_800EEC60_ovl00 func_800F72B8_ovl26
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
