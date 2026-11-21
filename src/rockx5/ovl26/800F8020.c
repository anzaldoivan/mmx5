#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "mmx5/ovl26.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "addr.h"

#define D_8007BD4C D_800FA610_ovl26

#define func_800532E0 func_800F8020_ovl26
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F58E4_ovl27 func_800F805C_ovl26
#include "shared/func_800F58E4_ovl27.c"
#undef func_800F58E4_ovl27

#define func_800F5B44_ovl27 func_800F82BC_ovl26
#define func_800F5950_ovl27 func_800F80C8_ovl26
#define func_800F59D8_ovl27 func_800F8150_ovl26
#include "shared/func_800F5950_ovl27.c"
#undef func_800F5950_ovl27
#undef func_800F5B44_ovl27
#undef func_800F59D8_ovl27

#define func_800F5A88_ovl27 func_800F8200_ovl26
#include "shared/func_800F5A88_ovl27.c"
#undef func_800F5A88_ovl27

#define func_800F5AB4_ovl27 func_800F822C_ovl26
#define func_800F5B44_ovl27 func_800F82BC_ovl26
#include "shared/func_800F5AB4_ovl27.c"
#undef func_800F5AB4_ovl27
#undef func_800F5B44_ovl27
