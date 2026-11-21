#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "addr.h"
#include "mmx5/ovl33.h"
#include "mmx5/ovl06.h"

#define func_800F02E4_ovl05 func_800FCCEC_ovl33
#define apply_object_motion animate_object
#include "shared/func_800F02E4_ovl05.c"
#undef func_800F02E4_ovl05
#undef apply_object_motion

#define func_800F9C9C_ovl06 func_800FCD30_ovl33
#include "shared/func_800F9C9C_ovl06.c"
#undef func_800F9C9C_ovl06

#define D_800FF1CC_ovl06 D_800FEACC_ovl33
#define D_800FF1D0_ovl06 D_800FEAD0_ovl33

#define func_800F9FFC_ovl06 func_800FCD8C_ovl33
#include "shared/func_800F9FFC_ovl06.c"
#undef func_800F9FFC_ovl06
#undef D_800FF1CC_ovl06
#undef D_800FF1D0_ovl06

#define D_800FF1CC_ovl06 D_800FEACC_ovl33
#define D_800FF1D0_ovl06 D_800FEAD0_ovl33
#define func_800FA858_ovl06 func_800FCE1C_ovl33
#define func_800FA8D8_ovl06 func_800FCE9C_ovl33
#define func_800FAF38_ovl06 func_800FD4FC_ovl33
#define func_800FA928_ovl06 func_800FCEEC_ovl33
#define func_800F9180_ovl06 func_800FB744_ovl33
#define func_800FAA00_ovl06 func_800FCFC4_ovl33
#include "shared/func_800FA858_ovl06.c"
#undef func_800FA858_ovl06
#undef D_800FF1CC_ovl06
#undef D_800FF1D0_ovl06
#undef func_800FA8D8_ovl06
#undef func_800FA928_ovl06
#undef func_800FAF38_ovl06
#undef func_800FAA00_ovl06
