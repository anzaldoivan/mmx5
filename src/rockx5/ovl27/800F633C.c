#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800EFA68_ovl21 D_800FD4A0_ovl27

#define func_800EF26C_ovl21 func_800F633C_ovl27
#include "shared/func_800EF26C_ovl21.c"
#undef func_800EF26C_ovl21
#undef D_800EFA68_ovl21

#define func_800EF93C_ovl05 func_800F6388_ovl27
#include "shared/func_800EF93C_ovl05.c"
#undef func_800EF93C_ovl05

#define D_800EEBA0_ovl00 func_800F63E8_ovl27
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
