#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define D_800F5028_ovl05 D_800FB374_ovl00

#define func_800EF8CC_ovl05 func_800F6234_ovl00
#include "shared/func_800EF8CC_ovl05.c"
#undef func_800EF8CC_ovl05
#undef D_800F5028_ovl05

#define func_800EF93C_ovl05 func_800F62A4_ovl00
#include "shared/func_800EF93C_ovl05.c"
#undef func_800EF93C_ovl05

#define D_800EEBA0_ovl00 func_800F6304_ovl00
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
