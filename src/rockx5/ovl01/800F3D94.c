#include "types.h"
#include "mmx5/graphics.h"

#define func_800F2330_ovl00 func_800F3D94_ovl01
#include "shared/func_800F2330_ovl00.c"
#undef func_800F2330_ovl00

#define func_800F237C_ovl00 func_800F3DE0_ovl01
#define func_800F2038_ovl00 func_800F3A9C_ovl01
#include "shared/func_800F237C_ovl00.c"
#undef func_800F237C_ovl00
#undef func_800F2038_ovl00

#define D_800FC6A4_ovl01 D_800FCCDC_ovl01
void func_800F4748_ovl01(u8*);
#define func_800F060C_ovl01 func_800F3E60_ovl01
#define func_800F074C_ovl01 func_800F4748_ovl01
#include "shared/func_800F060C_ovl01.c"
#undef func_800F060C_ovl01
#undef func_800F074C_ovl01
#undef D_800FC6A4_ovl01
