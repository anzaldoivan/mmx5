#include "types.h"
#include "addr.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"

#define D_8007BD4C D_800FA918_ovl00

#define func_800532E0 func_800F09B8_ovl00
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F09F4_ovl00.c"

#define D_8007BD4C D_800FA920_ovl00

#define func_800532E0 func_800F0B48_ovl00
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F0B84_ovl00.c"

#include "shared/func_800F0BCC_ovl00.c"
