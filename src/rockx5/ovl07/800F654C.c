#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"

#define D_8007BD4C D_801014C8_ovl07

#define func_800532E0 func_800F654C_ovl07
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F05EC_ovl08 func_800F6588_ovl07
#include "shared/func_800F05EC_ovl08.c"
#undef func_800F05EC_ovl08

#define D_8007BD4C D_801014CC_ovl07

#define func_800532E0 func_800F65E8_ovl07
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F0688_ovl08 func_800F6624_ovl07
#define func_800F06F4_ovl08 func_800F6690_ovl07
#define func_800F078C_ovl08 func_800F6728_ovl07
#include "shared/func_800F0688_ovl08.c"
#undef func_800F0688_ovl08
#undef func_800F06F4_ovl08
#undef func_800F078C_ovl08
