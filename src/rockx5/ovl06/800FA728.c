#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "addr.h"
#include "mmx5/ovl06.h"

#define func_800F02E4_ovl05 func_800FA728_ovl06
#define apply_object_motion animate_object
#include "shared/func_800F02E4_ovl05.c"
#undef func_800F02E4_ovl05
#undef apply_object_motion

#define func_800F9C9C_ovl06 func_800FA76C_ovl06
#include "shared/func_800F9C9C_ovl06.c"
#undef func_800F9C9C_ovl06

#define func_800F9FFC_ovl06 func_800FA7C8_ovl06
#include "shared/func_800F9FFC_ovl06.c"
#undef func_800F9FFC_ovl06

#include "shared/func_800FA858_ovl06.c"
