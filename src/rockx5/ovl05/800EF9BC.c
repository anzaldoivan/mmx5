#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "mmx5/system.h"
#include "mmx5/object.h"

#include "shared/func_800EF9BC_ovl05.c"

#define D_800F4844_ovl05 D_800F52D4_ovl05

#define func_800EEA80_ovl05 func_800EFCE8_ovl05
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#include "shared/func_800EFD24_ovl05.c"

#define D_800EEBA0_ovl00 func_800EFE0C_ovl05
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800EFE2C_ovl05
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#include "shared/func_800EFE4C_ovl05.c"

#define D_8007BD4C D_800F5310_ovl05

#define func_800532E0 func_800EFF10_ovl05
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800EFF4C_ovl05.c"

#define D_8007BD4C D_800F531C_ovl05

#define func_800532E0 func_800F009C_ovl05
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F00D8_ovl05.c"
