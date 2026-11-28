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

#include "shared/func_800FBEBC_ovl06.c"

#define D_800F4844_ovl05 D_800FF72C_ovl06

#define func_800EEA80_ovl05 func_800FBFFC_ovl06
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#include "shared/func_800FC038_ovl06.c"

#define D_800EEBA0_ovl00 func_800FC098_ovl06
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#include "shared/func_800FC0B8_ovl06.c"
