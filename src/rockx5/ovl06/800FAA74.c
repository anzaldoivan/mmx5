#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "addr.h"
#include "mmx5/ovl06.h"

#define func_800F02E4_ovl05 func_800FAA74_ovl06
#define apply_object_motion animate_object
#include "shared/func_800F02E4_ovl05.c"
#undef func_800F02E4_ovl05
#undef apply_object_motion

#define func_800F9C9C_ovl06 func_800FAAB8_ovl06
#include "shared/func_800F9C9C_ovl06.c"
#undef func_800F9C9C_ovl06

#include "shared/func_800FAB14_ovl06.c"
