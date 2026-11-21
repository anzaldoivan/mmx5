#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define func_800F2760_ovl02 func_800F51C0_ovl07
#define func_800F27A8_ovl02 func_800F5208_ovl07
#include "shared/func_800F2760_ovl02.c"
#undef func_800F2760_ovl02
#undef func_800F27A8_ovl02

#define D_8007BD4C D_8010127C_ovl07

#define func_800532E0 func_800F5274_ovl07
#include "shared/func_800532E0.c"
#undef func_800532E0
