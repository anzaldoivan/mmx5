#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define func_800F2870_ovl00 func_800F42D4_ovl01
#include "shared/func_800F2870_ovl00.c"
#undef func_800F2870_ovl00

#define func_800F28B4_ovl00 func_800F4318_ovl01
#define func_800F2038_ovl00 func_800F3A9C_ovl01
#include "shared/func_800F28B4_ovl00.c"
#undef func_800F28B4_ovl00
#undef func_800F2038_ovl00

#define D_8007BD4C D_800FCD04_ovl01

#define func_800532E0 func_800F4354_ovl01
#include "shared/func_800532E0.c"
#undef func_800532E0
