#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#include "shared/func_800F0370_ovl10.c"

#define D_800EEBA0_ovl00 func_800F0450_ovl10
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F0470_ovl10
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
