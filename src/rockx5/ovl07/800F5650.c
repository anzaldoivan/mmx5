#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/object.h"

#define D_800EEC60_ovl00 func_800F5650_ovl07
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define func_800F2BF8_ovl02 func_800F5658_ovl07
#define func_800F2C70_ovl02 func_800F56D0_ovl07
#define func_800F2CE8_ovl02 func_800F5748_ovl07
#define func_800F2D30_ovl02 func_800F5790_ovl07
#include "shared/func_800F2BF8_ovl02.c"
#undef func_800F2BF8_ovl02
#undef func_800F2C70_ovl02
#undef func_800F2CE8_ovl02
#undef func_800F2D30_ovl02

#define D_800EEBA0_ovl00 func_800F57F4_ovl07
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
