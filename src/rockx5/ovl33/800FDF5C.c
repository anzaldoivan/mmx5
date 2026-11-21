#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/object.h"

#define D_8007BD4C D_800FEFEC_ovl33

#define func_800532E0 func_800FDF5C_ovl33
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800FB9D4_ovl06 func_800FDF98_ovl33
#define func_800FBA04_ovl06 func_800FDFC8_ovl33
#define D_800FF6AC_ovl06 D_800FEFAC_ovl33
#define D_800FF6B0_ovl06 D_800FEFB0_ovl33
#define func_800FBA68_ovl06 func_800FE02C_ovl33
#include "shared/func_800FB9D4_ovl06.c"
#undef func_800FB9D4_ovl06
#undef func_800FBA04_ovl06
#undef func_800FBA68_ovl06
#undef D_800FF6AC_ovl06
#undef D_800FF6B0_ovl06

#define D_8007BD4C D_800FEFF8_ovl33

#define func_800532E0 func_800FE0B8_ovl33
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800FBB30_ovl06 func_800FE0F4_ovl33
#define D_800FF69C_ovl06 D_800FEF9C_ovl33
#define D_800FF6A0_ovl06 D_800FEFA0_ovl33
#define D_800FF6A4_ovl06 D_800FEFA4_ovl33
#define func_800FBB70_ovl06 func_800FE134_ovl33
#define func_800FBC28_ovl06 func_800FE1EC_ovl33
#include "shared/func_800FBB30_ovl06.c"
#undef func_800FBB30_ovl06
#undef func_800FBB70_ovl06
#undef D_800FF69C_ovl06
#undef D_800FF6A0_ovl06
#undef D_800FF6A4_ovl06
#undef func_800FBC28_ovl06

#define D_8007BD4C D_800FF004_ovl33

#define func_800532E0 func_800FE208_ovl33
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define D_800FF684_ovl06 D_800FEF84_ovl33
#define D_800FF688_ovl06 D_800FEF88_ovl33
#define func_800FBC80_ovl06 func_800FE244_ovl33
#define func_800FBD10_ovl06 func_800FE2D4_ovl33
#define D_800FF724_ovl06 D_800FF024_ovl33
#define func_800FBDC8_ovl06 func_800FE38C_ovl33
#include "shared/func_800FBC80_ovl06.c"
#undef func_800FBC80_ovl06
#undef D_800FF684_ovl06
#undef D_800FF688_ovl06
#undef func_800FBD10_ovl06
#undef func_800FBDC8_ovl06
