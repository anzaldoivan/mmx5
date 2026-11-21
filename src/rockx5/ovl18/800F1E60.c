#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800F4844_ovl05 D_800F79B0_ovl18

#define func_800EEA80_ovl05 func_800F1E60_ovl18
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define func_800F166C_ovl04 func_800F1E9C_ovl18
#define func_800F16EC_ovl04 func_800F1F1C_ovl18
#include "shared/func_800F166C_ovl04.c"
#undef func_800F166C_ovl04
#undef func_800F16EC_ovl04

#define D_800EEBA0_ovl00 func_800F1FFC_ovl18
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
