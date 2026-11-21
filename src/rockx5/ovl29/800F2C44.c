#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#define D_8007BD4C D_800F986C_ovl29

#define func_800532E0 func_800F2C44_ovl29
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F0F78_ovl11 func_800F3118_ovl29
#define func_800F1148_ovl11 func_800F32E8_ovl29
#define func_800F0AE0_ovl11 func_800F2C80_ovl29
#define func_800F0BE8_ovl11 func_800F2D88_ovl29
#include "shared/func_800F0AE0_ovl11.c"
#undef func_800F0AE0_ovl11
#undef func_800F0F78_ovl11
#undef func_800F1148_ovl11
#undef func_800F0BE8_ovl11
