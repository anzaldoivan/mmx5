#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#include "shared/func_800FC254_ovl07.c"

#define D_800FA778_ovl09 D_80101CCC_ovl07

#define func_800EF37C_ovl09 func_800FC350_ovl07
#include "shared/func_800EF37C_ovl09.c"
#undef func_800EF37C_ovl09
#undef D_800FA778_ovl09

#include "shared/func_800FC398_ovl07.c"

#define func_800F9E20_ovl27 func_800FC3D4_ovl07
#define clear_object_slot func_800FB030_ovl07
#include "shared/func_800F9E20_ovl27.c"
#undef func_800F9E20_ovl27
#undef clear_object_slot
