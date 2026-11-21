#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"

#define D_8007BD4C D_800FEFD8_ovl33

#define func_800532E0 func_800FDC28_ovl33
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800FB6A0_ovl06 func_800FDC64_ovl33
#define D_800FF684_ovl06 D_800FEF84_ovl33
#define D_800FF688_ovl06 D_800FEF88_ovl33
#define func_800FBD10_ovl06 func_800FE2D4_ovl33
#define func_800FB740_ovl06 func_800FDD04_ovl33
#define func_800FB7EC_ovl06 func_800FDDB0_ovl33
#include "shared/func_800FB6A0_ovl06.c"
#undef func_800FB6A0_ovl06
#undef func_800FB740_ovl06
#undef func_800FBD10_ovl06
#undef func_800FB7EC_ovl06
