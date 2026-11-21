#include "types.h"
#include "addr.h"

#define D_8007BD4C D_800FA8BC_ovl00

#define func_800532E0 func_800EFDC0_ovl00
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800EFDFC_ovl00.c"

#define D_8007BD4C D_800FA8C4_ovl00

#define func_800532E0 func_800EFF08_ovl00
#include "shared/func_800532E0.c"
#undef func_800532E0
