#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

#define func_800F3780_ovl00 func_800F51E4_ovl01
#include "shared/func_800F3780_ovl00.c"
#undef func_800F3780_ovl00

#define D_800EEBA0_ovl00 func_800F521C_ovl01
#define func_8002D720 apply_object_motion
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
