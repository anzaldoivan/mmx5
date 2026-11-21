#include "types.h"
#include "mmx5/globals.h"

#define D_8007BD4C D_80101EEC_ovl07

#define func_800532E0 func_800FEA20_ovl07
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800FEA5C_ovl07.c"

#define D_800EEC60_ovl00 func_800FEAC0_ovl07
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
