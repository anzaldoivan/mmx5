#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#define D_800FA214_ovl00 D_800FDCD8_ovl30

#define func_800EEB64_ovl00 func_800FB938_ovl30
#include "shared/func_800EEB64_ovl00.c"
#undef func_800EEB64_ovl00
#undef D_800FA214_ovl00

#define func_800F9D3C_ovl01 func_800FB974_ovl30
#define func_800F9DB8_ovl01 func_800FB9F0_ovl30
#include "shared/func_800F9D3C_ovl01.c"
#undef func_800F9D3C_ovl01
#undef func_800F9DB8_ovl01
