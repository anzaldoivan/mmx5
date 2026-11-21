#include "types.h"
#include "addr.h"

#define D_8007BD4C D_800FCBF8_ovl27

#define func_800532E0 func_800F0BE4_ovl27
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define D_800FA78C_ovl00 D_800FCAC8_ovl27
#define func_800EFDFC_ovl00 func_800F0C20_ovl27
#define D_800FA758_ovl00 D_800FCA94_ovl27
#define func_800EFE60_ovl00 func_800F0C84_ovl27
#include "shared/func_800EFDFC_ovl00.c"
#undef func_800EFDFC_ovl00
#undef D_800FA78C_ovl00
#undef func_800EFE60_ovl00
