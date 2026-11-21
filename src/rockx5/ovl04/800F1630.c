#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800F4844_ovl05 D_80101524_ovl04

#define func_800EEA80_ovl05 func_800F1630_ovl04
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#include "shared/func_800F166C_ovl04.c"

#define D_800EEBA0_ovl00 func_800F17CC_ovl04
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
