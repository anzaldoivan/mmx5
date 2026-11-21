#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800F4844_ovl05 D_800FA55C_ovl29

#define func_800EEA80_ovl05 func_800F7814_ovl29
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define func_800F1DB4_ovl11 func_800F7850_ovl29
#define func_800F1E04_ovl11 func_800F78A0_ovl29
#include "shared/func_800F1DB4_ovl11.c"
#undef func_800F1DB4_ovl11
#undef func_800F1E04_ovl11

#define D_800EEBA0_ovl00 func_800F7920_ovl29
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
