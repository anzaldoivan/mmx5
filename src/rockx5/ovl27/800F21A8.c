#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/title.h"

#define D_800F9570_ovl03 D_800FCE74_ovl27

#define func_800EECC0_ovl03 func_800F21A8_ovl27
#include "shared/func_800EECC0_ovl03.c"
#undef func_800EECC0_ovl03
#undef D_800F9570_ovl03

#define D_800F9374_ovl29 D_800FCE70_ovl27
#define D_800F9388_ovl29 D_800FCE84_ovl27
#define func_800F02BC_ovl29 func_800F21F4_ovl27
#define func_800F0394_ovl29 func_800F22CC_ovl27
#include "shared/func_800F02BC_ovl29.c"
#undef func_800F02BC_ovl29
#undef D_800F9374_ovl29
#undef D_800F9388_ovl29
#undef func_800F0394_ovl29

#define D_8007BD4C D_800FCEA0_ovl27

#define func_800532E0 func_800F2320_ovl27
#include "shared/func_800532E0.c"
#undef func_800532E0
