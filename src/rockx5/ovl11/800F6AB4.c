#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

#define D_800FA214_ovl00 D_800F9F4C_ovl11

#define func_800EEB64_ovl00 func_800F6AB4_ovl11
#include "shared/func_800EEB64_ovl00.c"
#undef func_800EEB64_ovl00
#undef D_800FA214_ovl00

#include "shared/func_800F6AF0_ovl11.c"

#define D_8007BD4C D_800F9F58_ovl11

#define func_800532E0 func_800F6C60_ovl11
#include "shared/func_800532E0.c"
#undef func_800532E0
