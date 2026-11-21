#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl34.h"
#include "mmx5/ovl07.h"
#include "mmx5/globals.h"

#define D_800FBE7C_ovl10 D_800FFF6C_ovl34

#define func_800F50E8_ovl10 func_800FD238_ovl34
#include "shared/func_800F50E8_ovl10.c"
#undef func_800F50E8_ovl10
#undef D_800FBE7C_ovl10

#define D_80101804_ovl07 D_800FFA60_ovl34
#define D_80101808_ovl07 D_800FFA64_ovl34
#define func_800FC928_ovl07 func_800FD280_ovl34
#define func_800FB030_ovl07 func_800FB988_ovl34
#define func_800FC988_ovl07 func_800FD2E0_ovl34
#include "shared/func_800FC928_ovl07.c"
#undef func_800FC928_ovl07
#undef D_80101804_ovl07
#undef D_80101808_ovl07
#undef func_800FC988_ovl07
#undef func_800FB030_ovl07

#define func_800F5C58_ovl27 func_800FD338_ovl34
#include "shared/func_800F5C58_ovl27.c"
#undef func_800F5C58_ovl27

#define func_800FA3D8_ovl27 func_800FD368_ovl34
#include "shared/func_800FA3D8_ovl27.c"
#undef func_800FA3D8_ovl27
