#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#include "shared/func_800F0068_ovl10.c"

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800F019C_ovl10
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#include "shared/func_800F01BC_ovl10.c"

#define D_800EEC60_ovl00 func_800F027C_ovl10
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
