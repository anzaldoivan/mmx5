#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define D_8007BD4C D_800F7AEC_ovl18

#define func_800532E0 func_800F3994_ovl18
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F2760_ovl02 func_800F39D0_ovl18
#define func_800F27A8_ovl02 func_800F3A18_ovl18
#include "shared/func_800F2760_ovl02.c"
#undef func_800F2760_ovl02
#undef func_800F27A8_ovl02

#define D_8007BD4C D_800F7AF4_ovl18

#define func_800532E0 func_800F3A84_ovl18
#include "shared/func_800532E0.c"
#undef func_800532E0
