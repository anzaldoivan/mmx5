#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define D_800FA214_ovl00 D_800FEE7C_ovl33

#define func_800EEB64_ovl00 func_800FBB50_ovl33
#include "shared/func_800EEB64_ovl00.c"
#undef func_800EEB64_ovl00
#undef D_800FA214_ovl00

#define func_800F95C8_ovl06 func_800FBB8C_ovl33
#include "shared/func_800F95C8_ovl06.c"
#undef func_800F95C8_ovl06

#define func_800F9648_ovl06 func_800FBC0C_ovl33
#include "shared/func_800F9648_ovl06.c"
#undef func_800F9648_ovl06
