#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "addr.h"
#include "mmx5/ovl33.h"
#include "mmx5/ovl06.h"

#define func_800F02E4_ovl05 func_800FD038_ovl33
#define apply_object_motion animate_object
#include "shared/func_800F02E4_ovl05.c"
#undef func_800F02E4_ovl05
#undef apply_object_motion

#define func_800F9C9C_ovl06 func_800FD07C_ovl33
#include "shared/func_800F9C9C_ovl06.c"
#undef func_800F9C9C_ovl06

#define D_800FF1CC_ovl06 D_800FEACC_ovl33
#define D_800FF1D0_ovl06 D_800FEAD0_ovl33
#define func_800FAB14_ovl06 func_800FD0D8_ovl33
#define D_800FF1D4_ovl06 D_800FEAD4_ovl33
#define D_800FF1D8_ovl06 D_800FEAD8_ovl33
#define func_800FABAC_ovl06 func_800FD170_ovl33
#define func_800FAC64_ovl06 func_800FD228_ovl33
#define func_800F9180_ovl06 func_800FB744_ovl33
#define func_800FACAC_ovl06 func_800FD270_ovl33
#include "shared/func_800FAB14_ovl06.c"
#undef func_800FAB14_ovl06
#undef D_800FF1CC_ovl06
#undef D_800FF1D0_ovl06
#undef func_800FABAC_ovl06
#undef D_800FF1D4_ovl06
#undef D_800FF1D8_ovl06
#undef func_800FAC64_ovl06
#undef func_800FACAC_ovl06
