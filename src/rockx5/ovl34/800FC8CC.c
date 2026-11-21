#include "types.h"
#include "mmx5/ovl34.h"
#include "addr.h"
#include "mmx5/ovl07.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

#define func_800FBF74_ovl07 func_800FC8CC_ovl34
#define func_800FB030_ovl07 func_800FB988_ovl34
#include "shared/func_800FBF74_ovl07.c"
#undef func_800FBF74_ovl07
#undef func_800FB030_ovl07

#define D_8007BD4C D_800FFF0C_ovl34

#define func_800532E0 func_800FC904_ovl34
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800FC9E0_ovl07 func_800FD338_ovl34
#define func_800FCB98_ovl07 func_800FD4F0_ovl34
#define func_800FBFE8_ovl07 func_800FC940_ovl34
#define func_800FC0EC_ovl07 func_800FCA44_ovl34
#define func_800FC15C_ovl07 func_800FCAB4_ovl34
#define func_800FC1CC_ovl07 func_800FCB24_ovl34
#define func_800FB030_ovl07 func_800FB988_ovl34
#include "shared/func_800FBFE8_ovl07.c"
#undef func_800FBFE8_ovl07
#undef func_800FC9E0_ovl07
#undef func_800FCB98_ovl07
#undef func_800FC0EC_ovl07
#undef func_800FC15C_ovl07
#undef func_800FC1CC_ovl07
#undef func_800FB030_ovl07

#define D_800FC6A4_ovl01 D_800FFF1C_ovl34

#define func_800F060C_ovl01 func_800FCB60_ovl34
#define func_800F074C_ovl01 animate_object
#include "shared/func_800F060C_ovl01.c"
#undef func_800F060C_ovl01
#undef func_800F074C_ovl01
