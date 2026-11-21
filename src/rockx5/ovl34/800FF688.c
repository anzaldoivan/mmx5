#include "types.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#define func_800FED30_ovl07 func_800FF688_ovl34
#include "shared/func_800FED30_ovl07.c"
#undef func_800FED30_ovl07

#define D_800F4844_ovl05 D_80100150_ovl34

#define func_800EEA80_ovl05 func_800FF7EC_ovl34
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define func_800FEED0_ovl07 func_800FF828_ovl34
#define func_800FEFEC_ovl07 func_800FF944_ovl34
#include "shared/func_800FEED0_ovl07.c"
#undef func_800FEED0_ovl07
#undef func_800FEFEC_ovl07

#define D_800EEBA0_ovl00 func_800FF9C8_ovl34
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
