#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"

#define D_8007BD4C D_800FBEB8_ovl10

#define func_800532E0 func_800F5958_ovl10
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F5994_ovl10.c"

#define D_800EEC60_ovl00 func_800F5BCC_ovl10
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800FBE7C_ovl10 D_800FBECC_ovl10

#define func_800F50E8_ovl10 func_800F5BD4_ovl10
#include "shared/func_800F50E8_ovl10.c"
#undef func_800F50E8_ovl10
#undef D_800FBE7C_ovl10

#include "shared/func_800F5C1C_ovl10.c"
