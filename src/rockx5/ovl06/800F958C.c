#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define D_800FA214_ovl00 D_800FF57C_ovl06

#define func_800EEB64_ovl00 func_800F958C_ovl06
#include "shared/func_800EEB64_ovl00.c"
#undef func_800EEB64_ovl00
#undef D_800FA214_ovl00

#include "shared/func_800F95C8_ovl06.c"

#include "shared/func_800F9648_ovl06.c"

#define D_8007BD4C D_800FF588_ovl06

#define func_800532E0 func_800F9748_ovl06
#include "shared/func_800532E0.c"
#undef func_800532E0
