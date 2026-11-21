#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"

#define D_8007BD4C D_800FED80_ovl36

#define func_800532E0 func_800FCB24_ovl36
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F5994_ovl10 func_800FCB60_ovl36
#define func_800F59EC_ovl10 func_800FCBB8_ovl36
#define D_800FBE00_ovl10 D_800FECC8_ovl36
#define func_800F6250_ovl10 func_800FD41C_ovl36
#define func_800F5AE0_ovl10 func_800FCCAC_ovl36
#include "shared/func_800F5994_ovl10.c"
#undef func_800F5994_ovl10
#undef func_800F59EC_ovl10
#undef func_800F5AE0_ovl10
#undef D_800FBE00_ovl10
#undef func_800F6250_ovl10

#define D_800EEC60_ovl00 func_800FCD98_ovl36
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800FBE7C_ovl10 D_800FED94_ovl36

#define func_800F50E8_ovl10 func_800FCDA0_ovl36
#include "shared/func_800F50E8_ovl10.c"
#undef func_800F50E8_ovl10
#undef D_800FBE7C_ovl10

#define func_800F5C1C_ovl10 func_800FCDE8_ovl36
#define func_800F5C90_ovl10 func_800FCE5C_ovl36
#define func_800F5CE8_ovl10 func_800FCEB4_ovl36
#define func_800F5CF8_ovl10 func_800FCEC4_ovl36
#define func_800F5D5C_ovl10 func_800FCF28_ovl36
#include "shared/func_800F5C1C_ovl10.c"
#undef func_800F5C1C_ovl10
#undef func_800F5C90_ovl10
#undef func_800F5CE8_ovl10
#undef func_800F5CF8_ovl10
#undef func_800F5D5C_ovl10
