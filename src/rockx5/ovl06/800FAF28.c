#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

#define func_800FA3D8_ovl27 func_800FAF28_ovl06
#include "shared/func_800FA3D8_ovl27.c"
#undef func_800FA3D8_ovl27

#include "shared/func_800FAF38_ovl06.c"

#define D_800F4844_ovl05 D_800FF6B4_ovl06

#define func_800EEA80_ovl05 func_800FB480_ovl06
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#include "shared/func_800FB4BC_ovl06.c"

#define D_800EEBA0_ovl00 func_800FB584_ovl06
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#include "shared/func_800FB5A4_ovl06.c"
