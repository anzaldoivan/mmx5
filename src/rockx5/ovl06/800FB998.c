#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/object.h"

#define D_8007BD4C D_800FF6EC_ovl06

#define func_800532E0 func_800FB998_ovl06
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800FB9D4_ovl06.c"

#define D_8007BD4C D_800FF6F8_ovl06

#define func_800532E0 func_800FBAF4_ovl06
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800FBB30_ovl06.c"

#define D_8007BD4C D_800FF704_ovl06

#define func_800532E0 func_800FBC44_ovl06
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800FBC80_ovl06.c"
