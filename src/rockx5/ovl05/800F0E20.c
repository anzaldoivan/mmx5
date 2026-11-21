#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/ovl05.h"
#include "mmx5/movement.h"

#define D_800EEBA0_ovl00 func_800F0E20_ovl05
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#include "shared/func_800F0E40_ovl05.c"

#define D_8007BD4C D_800F539C_ovl05

#define func_800532E0 func_800F0E94_ovl05
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F0ED0_ovl05.c"

#define D_8007BD4C D_800F53A4_ovl05

#define func_800532E0 func_800F0F40_ovl05
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F0F7C_ovl05.c"
