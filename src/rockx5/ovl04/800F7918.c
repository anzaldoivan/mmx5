#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define D_800EEBA0_ovl00 func_800F7918_ovl04
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#include "shared/func_800F7938_ovl04.c"

#define D_800EEC60_ovl00 func_800F7A2C_ovl04
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#include "shared/func_800F7A34_ovl04.c"
