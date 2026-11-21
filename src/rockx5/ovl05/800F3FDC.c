#include "types.h"
#include "mmx5/globals.h"

#define D_800F4844_ovl05 D_800F5904_ovl05

#define func_800EEA80_ovl05 func_800F3FDC_ovl05
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define D_800F9618_ovl26 D_800F5914_ovl05
#define func_800F1F10_ovl26 func_800F4018_ovl05
#define D_800F961C_ovl26 D_800F5918_ovl05
#define func_800F1F78_ovl26 func_800F4080_ovl05
#define func_800F2020_ovl26 func_800F4128_ovl05
#include "shared/func_800F1F10_ovl26.c"
#undef func_800F1F10_ovl26
#undef D_800F9618_ovl26
#undef func_800F1F78_ovl26
#undef D_800F961C_ovl26
#undef func_800F2020_ovl26

#define D_800EEBA0_ovl00 func_800F415C_ovl05
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
