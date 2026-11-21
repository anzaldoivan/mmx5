#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/ovl06.h"
#include "mmx5/movement.h"

#define func_800F3E90_ovl26 func_800F9784_ovl06
#include "shared/func_800F3E90_ovl26.c"
#undef func_800F3E90_ovl26

#include "shared/func_800F97BC_ovl06.c"

#define func_800EFFE4_ovl04 func_800F9858_ovl06
#include "shared/func_800EFFE4_ovl04.c"
#undef func_800EFFE4_ovl04

#include "shared/func_800F986C_ovl06.c"

#define D_8007BD4C D_800FF5AC_ovl06

#define func_800532E0 func_800F9A9C_ovl06
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F9AD8_ovl06.c"

#define D_8007BD4C D_800FF5B4_ovl06

#define func_800532E0 func_800F9B90_ovl06
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F9BCC_ovl06.c"

#define func_800F02E4_ovl05 func_800F9C58_ovl06
#define apply_object_motion animate_object
#include "shared/func_800F02E4_ovl05.c"
#undef func_800F02E4_ovl05
#undef apply_object_motion

#include "shared/func_800F9C9C_ovl06.c"

#include "shared/func_800F9CF8_ovl06.c"

#include "shared/func_800F9D90_ovl06.c"
