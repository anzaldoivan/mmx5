#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

#define D_800FD920_ovl38 D_800FD930_ovl38

#define func_800FC1DC_ovl38 func_800FC2E8_ovl38
#include "shared/func_800FC1DC_ovl38.c"
#undef func_800FC1DC_ovl38
#undef D_800FD920_ovl38

#define D_800FC6A4_ovl01 D_800FD938_ovl38

#define func_800F060C_ovl01 func_800FC34C_ovl38
#define func_800F074C_ovl01 animate_object
#include "shared/func_800F060C_ovl01.c"
#undef func_800F060C_ovl01
#undef func_800F074C_ovl01
