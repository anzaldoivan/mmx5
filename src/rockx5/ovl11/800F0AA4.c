#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#define D_8007BD4C D_800F98CC_ovl11

#define func_800532E0 func_800F0AA4_ovl11
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F0AE0_ovl11.c"
