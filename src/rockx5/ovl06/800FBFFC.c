#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

#define D_800F4844_ovl05 D_800FF72C_ovl06

#define func_800EEA80_ovl05 func_800FBFFC_ovl06
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#include "shared/func_800FC038_ovl06.c"

#define D_800EEBA0_ovl00 func_800FC098_ovl06
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#include "shared/func_800FC0B8_ovl06.c"
