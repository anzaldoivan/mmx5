#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

#define D_800FA214_ovl00 D_800FDB80_ovl37

#define func_800EEB64_ovl00 func_800FBAEC_ovl37
#include "shared/func_800EEB64_ovl00.c"
#undef func_800EEB64_ovl00
#undef D_800FA214_ovl00

#define func_800F6AF0_ovl11 func_800FBB28_ovl37
#define func_800F6B60_ovl11 func_800FBB98_ovl37
#include "shared/func_800F6AF0_ovl11.c"
#undef func_800F6AF0_ovl11
#undef func_800F6B60_ovl11

#define D_8007BD4C D_800FDB8C_ovl37

#define func_800532E0 func_800FBC98_ovl37
#include "shared/func_800532E0.c"
#undef func_800532E0
