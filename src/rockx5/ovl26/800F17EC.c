#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/title.h"

#include "shared/func_800F17EC_ovl26.c"

#define D_800F4844_ovl05 D_800F95B8_ovl26

#define func_800EEA80_ovl05 func_800F189C_ovl26
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#include "shared/func_800F18D8_ovl26.c"

#define D_800EEBA0_ovl00 func_800F19C0_ovl26
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800F19E0_ovl26
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#include "shared/func_800F1A00_ovl26.c"
