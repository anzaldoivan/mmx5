#include "types.h"
#include "mmx5/globals.h"

#define D_8007BD4C D_801000B0_ovl34

#define func_800532E0 func_800FEDE8_ovl34
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800FEA5C_ovl07 func_800FEE24_ovl34
#include "shared/func_800FEA5C_ovl07.c"
#undef func_800FEA5C_ovl07

#define D_800EEC60_ovl00 func_800FEE88_ovl34
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
