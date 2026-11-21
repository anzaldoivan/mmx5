#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

#define D_8007BD4C D_800F96C0_ovl03

#define func_800532E0 func_800EFA70_ovl03
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800EFAAC_ovl03.c"

#include "shared/func_800EFAD8_ovl03.c"

#define D_800FA778_ovl09 D_800F96B8_ovl03

void func_800EFCD8_ovl03(X4_Obj*);
#define func_800EF37C_ovl09 func_800EFB98_ovl03
#define animate_object func_800EFCD8_ovl03
#include "shared/func_800EF37C_ovl09.c"
#undef func_800EF37C_ovl09
#undef animate_object
