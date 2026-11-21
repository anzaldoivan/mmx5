#include "types.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#include "shared/func_800FED30_ovl07.c"

#define D_800F4844_ovl05 D_80101EF4_ovl07

#define func_800EEA80_ovl05 func_800FEE94_ovl07
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#include "shared/func_800FEED0_ovl07.c"

#define D_800EEBA0_ovl00 func_800FF070_ovl07
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
