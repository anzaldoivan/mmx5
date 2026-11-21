#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define D_800F4844_ovl05 D_800FD4C8_ovl27

#define func_800EEA80_ovl05 func_800F6540_ovl27
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define func_800F6114_ovl29 func_800F657C_ovl27
#include "shared/func_800F6114_ovl29.c"
#undef func_800F6114_ovl29

#define D_800EEBA0_ovl00 func_800F6654_ovl27
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
