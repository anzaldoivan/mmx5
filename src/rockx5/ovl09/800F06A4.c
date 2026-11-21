#include "types.h"
#include "mmx5/ovl09.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

#define D_800FC6A4_ovl01 D_800FA9AC_ovl09

#define func_800F060C_ovl01 func_800F06A4_ovl09
#define func_800F074C_ovl01 func_800F07E4_ovl09
#include "shared/func_800F060C_ovl01.c"
#undef func_800F060C_ovl01
#undef func_800F074C_ovl01
#undef D_800FC6A4_ovl01

#define func_800F0658_ovl01 func_800F06F0_ovl09
#define func_800F06A8_ovl01 func_800F0740_ovl09
#define func_800F06FC_ovl01 func_800F0794_ovl09
#define func_800F074C_ovl01 func_800F07E4_ovl09
#include "shared/func_800F0658_ovl01.c"
#undef func_800F0658_ovl01
#undef func_800F06A8_ovl01
#undef func_800F06FC_ovl01
#undef func_800F074C_ovl01
