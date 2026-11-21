#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define D_8007BD4C D_800F4750_ovl02

#define func_800532E0 func_800F2724_ovl02
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F2760_ovl02.c"

#define D_8007BD4C D_800F4758_ovl02

#define func_800532E0 func_800F2814_ovl02
#include "shared/func_800532E0.c"
#undef func_800532E0
