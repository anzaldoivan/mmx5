#include "types.h"
#include "mmx5/ovl04.h"
#include "mmx5/object.h"

#define D_8007BD4C D_80101514_ovl04

#define func_800532E0 func_800F1410_ovl04
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F144C_ovl04.c"

#define D_8007BD4C D_8010151C_ovl04

#define func_800532E0 func_800F1508_ovl04
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F1544_ovl04.c"

#define D_800EEC60_ovl00 func_800F1628_ovl04
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
