#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#include "shared/func_800F5DE0_ovl10.c"

#define D_8007BD4C D_800FBF00_ovl10

#define func_800532E0 func_800F5F84_ovl10
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F5FC0_ovl10.c"

#define D_8007BD4C D_800FBF14_ovl10

#define func_800532E0 func_800F60BC_ovl10
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F60F8_ovl10.c"

#define func_800EFCD8_ovl03 func_800F6250_ovl10
#include "shared/func_800EFCD8_ovl03.c"
#undef func_800EFCD8_ovl03
