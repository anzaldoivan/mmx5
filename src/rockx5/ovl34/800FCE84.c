#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl34.h"
#include "mmx5/globals.h"
#include "mmx5/ovl07.h"

#define D_8010180C_ovl07 D_800FFA68_ovl34
#define D_80101810_ovl07 D_800FFA6C_ovl34
#define func_800FC52C_ovl07 func_800FCE84_ovl34
#define D_80101804_ovl07 D_800FFA60_ovl34
#define D_80101808_ovl07 D_800FFA64_ovl34
#define func_800FC5A4_ovl07 func_800FCEFC_ovl34
#define func_800FB030_ovl07 func_800FB988_ovl34
#include "shared/func_800FC52C_ovl07.c"
#undef func_800FC52C_ovl07
#undef D_8010180C_ovl07
#undef D_80101810_ovl07
#undef func_800FC5A4_ovl07
#undef func_800FB030_ovl07
#undef D_80101804_ovl07
#undef D_80101808_ovl07

#define D_8007BD4C D_800FFF44_ovl34

#define func_800532E0 func_800FCF4C_ovl34
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800FCAD8_ovl07 func_800FD430_ovl34

#define func_800FC630_ovl07 func_800FCF88_ovl34
#include "shared/func_800FC630_ovl07.c"
#undef func_800FC630_ovl07
#undef func_800FCAD8_ovl07

#define func_800F6624_ovl01 func_800FD01C_ovl34
#include "shared/func_800F6624_ovl01.c"
#undef func_800F6624_ovl01

#define func_800FC718_ovl07 func_800FD070_ovl34
#define func_800FB030_ovl07 func_800FB988_ovl34
#define func_800FC7D4_ovl07 func_800FD12C_ovl34
#include "shared/func_800FC718_ovl07.c"
#undef func_800FC718_ovl07
#undef func_800FC7D4_ovl07
