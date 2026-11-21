#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define D_800F4844_ovl05 D_800FDC58_ovl01

#define func_800EEA80_ovl05 func_800FB804_ovl01
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#include "shared/func_800FB840_ovl01.c"

#define D_800EEBA0_ovl00 func_800FB910_ovl01
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
