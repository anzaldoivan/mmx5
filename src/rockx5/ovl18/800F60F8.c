#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl18.h"
#include "mmx5/system.h"

#define func_800F5524_ovl27 func_800F60F8_ovl18
#include "shared/func_800F5524_ovl27.c"
#undef func_800F5524_ovl27

#define func_800F59D8_ovl27 func_800F65AC_ovl18
#define func_800F5C58_ovl27 func_800F682C_ovl18
#define func_800F55A0_ovl27 func_800F6174_ovl18
#define func_800F5648_ovl27 func_800F621C_ovl18
#include "shared/func_800F55A0_ovl27.c"
#undef func_800F55A0_ovl27
#undef func_800F59D8_ovl27
#undef func_800F5C58_ovl27
#undef func_800F5648_ovl27

#define D_8007BD4C D_800F80AC_ovl18

#define func_800532E0 func_800F624C_ovl18
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F56B4_ovl27 func_800F6288_ovl18
#include "shared/func_800F56B4_ovl27.c"
#undef func_800F56B4_ovl27

#define func_800F572C_ovl27 func_800F6300_ovl18
#define func_800F59D8_ovl27 func_800F65AC_ovl18
#include "shared/func_800F572C_ovl27.c"
#undef func_800F572C_ovl27
#undef func_800F59D8_ovl27

#define D_8007BD4C D_800F80B4_ovl18

#define func_800532E0 func_800F634C_ovl18
#include "shared/func_800532E0.c"
#undef func_800532E0
