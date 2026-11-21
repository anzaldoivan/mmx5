#include "types.h"
#include "mmx5/globals.h"

#define D_800EEBA0_ovl00 func_800EFB84_ovl09
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800EFBA4_ovl09
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800EEC60_ovl00 func_800EFBAC_ovl09
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
