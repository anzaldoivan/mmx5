#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800EFA68_ovl21 D_800FC858_ovl01

#define func_800EF26C_ovl21 func_800F23BC_ovl01
#include "shared/func_800EF26C_ovl21.c"
#undef func_800EF26C_ovl21
#undef D_800EFA68_ovl21

#define func_800EF93C_ovl05 func_800F2408_ovl01
#include "shared/func_800EF93C_ovl05.c"
#undef func_800EF93C_ovl05

#define D_800EEBA0_ovl00 func_800F2468_ovl01
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
