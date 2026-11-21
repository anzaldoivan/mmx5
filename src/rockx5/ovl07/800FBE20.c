#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl07.h"

#define D_800FC6A4_ovl01 D_80101C98_ovl07

#define func_800F060C_ovl01 func_800FBE20_ovl07
#define func_800F074C_ovl01 animate_object
#include "shared/func_800F060C_ovl01.c"
#undef func_800F060C_ovl01
#undef func_800F074C_ovl01
#undef D_800FC6A4_ovl01

#include "shared/func_800FBE6C_ovl07.c"
