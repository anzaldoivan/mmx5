#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/ovl06.h"

#define func_800F02E4_ovl05 func_800F9E14_ovl06
#define apply_object_motion animate_object
#include "shared/func_800F02E4_ovl05.c"
#undef func_800F02E4_ovl05
#undef apply_object_motion

#include "shared/func_800F9E58_ovl06.c"

#include "shared/func_800F9EA8_ovl06.c"

#include "shared/func_800F9FFC_ovl06.c"

#include "shared/func_800FA08C_ovl06.c"

#define func_800F9D90_ovl06 func_800FA0D0_ovl06
#include "shared/func_800F9D90_ovl06.c"
#undef func_800F9D90_ovl06
