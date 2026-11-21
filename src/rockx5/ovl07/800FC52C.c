#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl07.h"
#include "mmx5/globals.h"

#include "shared/func_800FC52C_ovl07.c"

#define D_8007BD4C D_80101CE8_ovl07

#define func_800532E0 func_800FC5F4_ovl07
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800FC630_ovl07.c"

#define func_800F6624_ovl01 func_800FC6C4_ovl07
#include "shared/func_800F6624_ovl01.c"
#undef func_800F6624_ovl01

#include "shared/func_800FC718_ovl07.c"
