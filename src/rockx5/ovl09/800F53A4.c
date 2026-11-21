#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#include "shared/func_800F53A4_ovl09.c"

#define D_800EEBA0_ovl00 func_800F5458_ovl09
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F5478_ovl09
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
