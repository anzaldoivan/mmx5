#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/object.h"

#define D_800EEC60_ovl00 func_800F2BF0_ovl02
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#include "shared/func_800F2BF8_ovl02.c"

#define D_800EEBA0_ovl00 func_800F2D94_ovl02
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
