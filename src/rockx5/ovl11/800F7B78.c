#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "addr.h"

#define D_8007BD4C D_800F9FC4_ovl11

#define func_800532E0 func_800F7B78_ovl11
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F7BB4_ovl11.c"

#include "shared/func_800F7DD0_ovl11.c"

#include "shared/func_800F7EC0_ovl11.c"

#define D_8007BD4C D_800F9FF0_ovl11

#define func_800532E0 func_800F7FA4_ovl11
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F7FE0_ovl11.c"
