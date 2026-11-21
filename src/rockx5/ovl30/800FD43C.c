#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define D_800F4844_ovl05 D_800FDE40_ovl30

#define func_800EEA80_ovl05 func_800FD43C_ovl30
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define func_800FB840_ovl01 func_800FD478_ovl30
#include "shared/func_800FB840_ovl01.c"
#undef func_800FB840_ovl01

#define D_800EEBA0_ovl00 func_800FD548_ovl30
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
