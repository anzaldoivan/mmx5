#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define D_800EEBA0_ovl00 func_800F33C0_ovl11
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F33E0_ovl11
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
