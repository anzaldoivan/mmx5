#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl07.h"
#include "mmx5/globals.h"

#define D_800FBE7C_ovl10 D_80101D10_ovl07

#define func_800F50E8_ovl10 func_800FC8E0_ovl07
#include "shared/func_800F50E8_ovl10.c"
#undef func_800F50E8_ovl10
#undef D_800FBE7C_ovl10

#include "shared/func_800FC928_ovl07.c"

#define func_800F5C58_ovl27 func_800FC9E0_ovl07
#include "shared/func_800F5C58_ovl27.c"
#undef func_800F5C58_ovl27

#define func_800FA3D8_ovl27 func_800FCA10_ovl07
#include "shared/func_800FA3D8_ovl27.c"
#undef func_800FA3D8_ovl27
