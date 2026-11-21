#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define D_8007BD4C D_8010150C_ovl04

#define func_800532E0 func_800F1304_ovl04
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F1340_ovl04.c"

#define D_800EEBA0_ovl00 func_800F13F0_ovl04
#define func_8002D720 move_object
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
