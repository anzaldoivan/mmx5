#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/ovl06.h"

#define func_800F02E4_ovl05 func_800FA154_ovl06
#define apply_object_motion animate_object
#include "shared/func_800F02E4_ovl05.c"
#undef func_800F02E4_ovl05
#undef apply_object_motion

#include "shared/func_800FA198_ovl06.c"

#define D_8007BD4C D_800FF608_ovl06

#define func_800532E0 func_800FA374_ovl06
#include "shared/func_800532E0.c"
#undef func_800532E0
