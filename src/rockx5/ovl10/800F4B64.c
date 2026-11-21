#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#define D_800FA214_ovl00 D_800FBE54_ovl10

#define func_800EEB64_ovl00 func_800F4B64_ovl10
#include "shared/func_800EEB64_ovl00.c"
#undef func_800EEB64_ovl00
#undef D_800FA214_ovl00

#include "shared/func_800F4BA0_ovl10.c"

#include "shared/func_800F4C30_ovl10.c"

#define D_8007BD4C D_800FBE60_ovl10

#define func_800532E0 func_800F4D48_ovl10
#include "shared/func_800532E0.c"
#undef func_800532E0
