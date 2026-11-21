#include "types.h"
#include "addr.h"
#include "mmx5/graphics.h"

#define D_8007BD4C D_800FCC54_ovl27

#define func_800532E0 func_800F17DC_ovl27
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F09F4_ovl00 func_800F1818_ovl27
#define D_800FA75C_ovl00 D_800FCA98_ovl27
#define D_800FA77C_ovl00 D_800FCAB8_ovl27
#define func_800F0A84_ovl00 func_800F18A8_ovl27
#include "shared/func_800F09F4_ovl00.c"
#undef func_800F09F4_ovl00
#undef func_800F0A84_ovl00
#undef D_800FA75C_ovl00
#undef D_800FA77C_ovl00

#define D_8007BD4C D_800FCC5C_ovl27

#define func_800532E0 func_800F196C_ovl27
#include "shared/func_800532E0.c"
#undef func_800532E0
