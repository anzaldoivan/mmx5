#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

#define D_800F4FC8_ovl05 D_800FA03C_ovl11

#define func_800EF244_ovl05 func_800F823C_ovl11
#include "shared/func_800EF244_ovl05.c"
#undef func_800EF244_ovl05
#undef D_800F4FC8_ovl05

#include "shared/func_800F8298_ovl11.c"

#define func_800EFFE4_ovl04 func_800F8378_ovl11
#include "shared/func_800EFFE4_ovl04.c"
#undef func_800EFFE4_ovl04

#include "shared/func_800F838C_ovl11.c"

#define func_800F19C8_ovl04 func_800F8420_ovl11
#include "shared/func_800F19C8_ovl04.c"
#undef func_800F19C8_ovl04

#define D_8007BD4C D_800FA004_ovl11

#define func_800532E0 func_800F8430_ovl11
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F846C_ovl11.c"
