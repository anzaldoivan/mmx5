#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

#define D_800F9B84_ovl11 D_800FADF4_ovl00
#define D_800F9B88_ovl11 D_800FADF8_ovl00
#define D_800F9B8C_ovl11 D_800FADFC_ovl00
#define func_800F306C_ovl11 func_800F3834_ovl00
#define func_800F3230_ovl11 func_800F39F8_ovl00
#include "shared/func_800F306C_ovl11.c"
#undef func_800F306C_ovl11
#undef D_800F9B84_ovl11
#undef D_800F9B88_ovl11
#undef D_800F9B8C_ovl11
#undef func_800F3230_ovl11

#define D_800F4844_ovl05 D_800FAE04_ovl00

#define func_800EEA80_ovl05 func_800F3B4C_ovl00
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
