#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl34.h"
#include "mmx5/ovl07.h"

#define D_800FC6A4_ovl01 D_800FFEF4_ovl34

#define func_800F060C_ovl01 func_800FC778_ovl34
#define func_800F074C_ovl01 animate_object
#include "shared/func_800F060C_ovl01.c"
#undef func_800F060C_ovl01
#undef func_800F074C_ovl01
#undef D_800FC6A4_ovl01

#define func_800FCB98_ovl07 func_800FD4F0_ovl34
#define func_800FBE6C_ovl07 func_800FC7C4_ovl34
#define func_800FB030_ovl07 func_800FB988_ovl34
#define func_800FC9E0_ovl07 func_800FD338_ovl34
#define func_800FBECC_ovl07 func_800FC824_ovl34
#include "shared/func_800FBE6C_ovl07.c"
#undef func_800FBE6C_ovl07
#undef func_800FCB98_ovl07
#undef func_800FBECC_ovl07
