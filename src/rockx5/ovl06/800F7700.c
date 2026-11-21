#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

#define D_8007BD4C D_800FF164_ovl06

#define func_800532E0 func_800F7700_ovl06
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800EFAAC_ovl03 func_800F773C_ovl06
#include "shared/func_800EFAAC_ovl03.c"
#undef func_800EFAAC_ovl03

#define func_800EFAD8_ovl03 func_800F7768_ovl06
#define D_800F959C_ovl03 D_800FF040_ovl06
#define D_800F95A4_ovl03 D_800FF048_ovl06
#define func_800EFB20_ovl03 func_800F77B0_ovl06
#include "shared/func_800EFAD8_ovl03.c"
#undef func_800EFAD8_ovl03
#undef func_800EFB20_ovl03
#undef D_800F959C_ovl03
#undef D_800F95A4_ovl03

#define D_800FA778_ovl09 D_800FF15C_ovl06

void func_800F7968_ovl06(X4_Obj*);
#define func_800EF37C_ovl09 func_800F7828_ovl06
#define animate_object func_800F7968_ovl06
#include "shared/func_800EF37C_ovl09.c"
#undef func_800EF37C_ovl09
#undef animate_object
