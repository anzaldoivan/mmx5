#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"

#define D_8007BD4C D_800FA010_ovl11

#define func_800532E0 func_800F8548_ovl11
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F8584_ovl11.c"

#define D_800EEC60_ovl00 func_800F8608_ovl11
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
