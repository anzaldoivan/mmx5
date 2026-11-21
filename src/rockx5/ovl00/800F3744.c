#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

#define D_8007BD4C D_800FADE4_ovl00

#define func_800532E0 func_800F3744_ovl00
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F3780_ovl00.c"

#define D_800EEBA0_ovl00 func_800F37B8_ovl00
#define func_8002D720 apply_object_motion
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
