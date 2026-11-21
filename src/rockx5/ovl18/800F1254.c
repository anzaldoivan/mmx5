#include "types.h"
#include "mmx5/ovl18.h"
#include "mmx5/ovl04.h"
#include "mmx5/object.h"
#include "addr.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

#define D_80101480_ovl04 D_800F790C_ovl18
#define func_800F0FF4_ovl04 func_800F1824_ovl18

#define func_800F0A24_ovl04 func_800F1254_ovl18
#include "shared/func_800F0A24_ovl04.c"
#undef func_800F0A24_ovl04
#undef D_80101480_ovl04
#undef func_800F0FF4_ovl04

#define D_800F4844_ovl05 D_800F7928_ovl18

#define func_800EEA80_ovl05 func_800F1374_ovl18
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define D_80101478_ovl04 D_800F7904_ovl18
#define D_801014AC_ovl04 D_800F7938_ovl18
#define func_800F1080_ovl04 func_800F18B0_ovl18

#define func_800F0B80_ovl04 func_800F13B0_ovl18
#include "shared/func_800F0B80_ovl04.c"
#undef func_800F0B80_ovl04
#undef D_80101478_ovl04
#undef D_801014AC_ovl04
#undef func_800F1080_ovl04

#define func_800F0C70_ovl04 func_800F14A0_ovl18
#include "shared/func_800F0C70_ovl04.c"
#undef func_800F0C70_ovl04

#define func_8002D760 func_8002D7A0

#define func_800F0C70_ovl04 func_800F14E0_ovl18
#include "shared/func_800F0C70_ovl04.c"
#undef func_800F0C70_ovl04
