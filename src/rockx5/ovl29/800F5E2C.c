#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

#define D_800F5008_ovl05 D_800FA42C_ovl29

#define func_800EF424_ovl05 func_800F5E2C_ovl29
#include "shared/func_800EF424_ovl05.c"
#undef func_800EF424_ovl05
#undef D_800F5008_ovl05

#define func_800F0370_ovl10 func_800F5E98_ovl29
#include "shared/func_800F0370_ovl10.c"
#undef func_800F0370_ovl10

#define D_800EEBA0_ovl00 func_800F5F78_ovl29
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F5F98_ovl29
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
