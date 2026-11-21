#include "types.h"
#include "addr.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define func_800FB930_ovl01 func_800FD568_ovl30
#include "shared/func_800FB930_ovl01.c"
#undef func_800FB930_ovl01

#define D_800F4844_ovl05 D_800FDE4C_ovl30

#define func_800EEA80_ovl05 func_800FD680_ovl30
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define func_800FBA84_ovl01 func_800FD6BC_ovl30
#include "shared/func_800FBA84_ovl01.c"
#undef func_800FBA84_ovl01

#define D_800EEBA0_ovl00 func_800FD740_ovl30
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
