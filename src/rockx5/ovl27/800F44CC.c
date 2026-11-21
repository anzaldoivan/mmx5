#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define D_800EEBA0_ovl00 func_800F44CC_ovl27
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F44EC_ovl27
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800F4EC0_ovl05 D_800FD170_ovl27

#define func_800EF2C8_ovl05 func_800F44F4_ovl27
#include "shared/func_800EF2C8_ovl05.c"
#undef func_800EF2C8_ovl05
#undef D_800F4EC0_ovl05

#define D_8007BD4C D_800FD298_ovl27

#define func_800532E0 func_800F4580_ovl27
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define D_800F4FC0_ovl05 D_800FD270_ovl27

#define func_800EF390_ovl05 func_800F45BC_ovl27
#include "shared/func_800EF390_ovl05.c"
#undef func_800EF390_ovl05
