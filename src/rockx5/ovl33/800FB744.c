#include "types.h"
#include "mmx5/ovl33.h"
#include "mmx5/system.h"
#include "addr.h"

#define D_800FF170_ovl06 D_800FEA70_ovl33
#define D_800FF17C_ovl06 D_800FEA7C_ovl33
#define D_800FF188_ovl06 D_800FEA88_ovl33
#define D_800FF194_ovl06 D_800FEA94_ovl33

#define func_800F9180_ovl06 func_800FB744_ovl33
#include "shared/func_800F9180_ovl06.c"
#undef func_800F9180_ovl06
#undef D_800FF170_ovl06
#undef D_800FF17C_ovl06
#undef D_800FF188_ovl06
#undef D_800FF194_ovl06

#define D_800F4844_ovl05 D_800FEE40_ovl33

#define func_800EEA80_ovl05 func_800FBB14_ovl33
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
