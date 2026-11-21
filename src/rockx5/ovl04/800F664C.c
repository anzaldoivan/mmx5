#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

#include "shared/func_800F664C_ovl04.c"

#define D_800EEC60_ovl00 func_800F69D8_ovl04
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#include "shared/func_800F69E0_ovl04.c"

#define D_800EEBA0_ovl00 func_800F6AB0_ovl04
#define func_8002D720 move_object
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
