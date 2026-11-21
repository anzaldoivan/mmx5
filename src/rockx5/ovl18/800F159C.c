#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "addr.h"

#define D_8007BD4C D_800F796C_ovl18

#define func_800532E0 func_800F159C_ovl18
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F0DA8_ovl04 func_800F15D8_ovl18
#include "shared/func_800F0DA8_ovl04.c"
#undef func_800F0DA8_ovl04

#define D_8007BD4C D_800F7974_ovl18

#define func_800532E0 func_800F1618_ovl18
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F0E24_ovl04 func_800F1654_ovl18
#define func_800F0E6C_ovl04 func_800F169C_ovl18
#include "shared/func_800F0E24_ovl04.c"
#undef func_800F0E24_ovl04
#undef func_800F0E6C_ovl04

#define D_8007BD4C D_800F7980_ovl18

#define func_800532E0 func_800F16D8_ovl18
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F0EE4_ovl04 func_800F1714_ovl18
#define func_800F0F2C_ovl04 func_800F175C_ovl18
#define func_800F0F6C_ovl04 func_800F179C_ovl18
#include "shared/func_800F0EE4_ovl04.c"
#undef func_800F0EE4_ovl04
#undef func_800F0F2C_ovl04
#undef func_800F0F6C_ovl04
