#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/ovl06.h"
#include "addr.h"

#define D_8007BD4C D_800FF668_ovl06

#define func_800532E0 func_800FACF4_ovl06
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800FAD30_ovl06.c"
