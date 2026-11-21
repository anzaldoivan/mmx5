#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/object.h"

#define D_800EEC60_ovl00 func_800F3E60_ovl18
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define func_800F2BF8_ovl02 func_800F3E68_ovl18
#define func_800F2C70_ovl02 func_800F3EE0_ovl18
#define func_800F2CE8_ovl02 func_800F3F58_ovl18
#define func_800F2D30_ovl02 func_800F3FA0_ovl18
#include "shared/func_800F2BF8_ovl02.c"
#undef func_800F2BF8_ovl02
#undef func_800F2C70_ovl02
#undef func_800F2CE8_ovl02
#undef func_800F2D30_ovl02

#define D_800EEBA0_ovl00 func_800F4004_ovl18
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
