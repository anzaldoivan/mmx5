#include "types.h"
#include "mmx5/ovl34.h"
#include "mmx5/ovl07.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define func_800FC9E0_ovl07 func_800FD338_ovl34
#define func_800FCB98_ovl07 func_800FD4F0_ovl34
#define func_800FC254_ovl07 func_800FCBAC_ovl34
#define func_800FC308_ovl07 func_800FCC60_ovl34
#define func_800FB030_ovl07 func_800FB988_ovl34
#include "shared/func_800FC254_ovl07.c"
#undef func_800FC254_ovl07
#undef func_800FC9E0_ovl07
#undef func_800FCB98_ovl07
#undef func_800FC308_ovl07
#undef func_800FB030_ovl07

#define D_800FA778_ovl09 D_800FFF28_ovl34

#define func_800EF37C_ovl09 func_800FCCA8_ovl34
#include "shared/func_800EF37C_ovl09.c"
#undef func_800EF37C_ovl09
#undef D_800FA778_ovl09

#define func_800FC9E0_ovl07 func_800FD338_ovl34

#define func_800FC398_ovl07 func_800FCCF0_ovl34
#include "shared/func_800FC398_ovl07.c"
#undef func_800FC398_ovl07
#undef func_800FC9E0_ovl07

#define func_800F9E20_ovl27 func_800FCD2C_ovl34
#define clear_object_slot func_800FB988_ovl34
#include "shared/func_800F9E20_ovl27.c"
#undef func_800F9E20_ovl27
#undef clear_object_slot
