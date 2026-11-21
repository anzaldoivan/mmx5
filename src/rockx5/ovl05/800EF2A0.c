#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

#define D_800EEBA0_ovl00 func_800EF2A0_ovl05
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800EF2C0_ovl05
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#include "shared/func_800EF2C8_ovl05.c"

#define D_8007BD4C D_800F4FE8_ovl05

#define func_800532E0 func_800EF354_ovl05
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800EF390_ovl05.c"

#include "shared/func_800EF424_ovl05.c"

#include "shared/func_800EF490_ovl05.c"

#define D_800EEBA0_ovl00 func_800EF658_ovl05
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800EF678_ovl05
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
