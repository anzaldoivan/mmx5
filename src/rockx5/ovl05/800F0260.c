#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "addr.h"

#define D_8007BD4C D_800F5328_ovl05

#define func_800532E0 func_800F0260_ovl05
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F029C_ovl05.c"

#include "shared/func_800F02E4_ovl05.c"

#include "shared/func_800F0328_ovl05.c"

#include "shared/func_800F0404_ovl05.c"

#define D_8007BD4C D_800F533C_ovl05

#define func_800532E0 func_800F0428_ovl05
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F0464_ovl05.c"

#define func_800F0404_ovl05 func_800F04B8_ovl05
#include "shared/func_800F0404_ovl05.c"
#undef func_800F0404_ovl05
