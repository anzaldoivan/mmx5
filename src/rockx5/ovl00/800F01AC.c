#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

#include "shared/func_800F01AC_ovl00.c"

#define D_8007BD4C D_800FA8DC_ovl00

#define func_800532E0 func_800F03B8_ovl00
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F03F4_ovl00.c"

#include "shared/func_800F04E8_ovl00.c"

#define D_8007BD4C D_800FA8EC_ovl00

#define func_800532E0 func_800F0558_ovl00
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F03F4_ovl00 func_800F0594_ovl00
#define func_800F0418_ovl00 func_800F05B8_ovl00
#define func_800F0494_ovl00 func_800F0634_ovl00
#include "shared/func_800F03F4_ovl00.c"
#undef func_800F03F4_ovl00
#undef func_800F0418_ovl00
#undef func_800F0494_ovl00

#include "shared/func_800F0688_ovl00.c"

#define D_8007BD4C D_800FA8FC_ovl00

#define func_800532E0 func_800F0710_ovl00
#include "shared/func_800532E0.c"
#undef func_800532E0
