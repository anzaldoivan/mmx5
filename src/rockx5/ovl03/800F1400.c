#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/ovl03.h"
#include "mmx5/ovl05.h"
#include "mmx5/movement.h"

#define D_800EEBA0_ovl00 func_800F1400_ovl03
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800F5374_ovl05 D_800F9A24_ovl03

#define func_800F0E40_ovl05 func_800F1420_ovl03
#include "shared/func_800F0E40_ovl05.c"
#undef func_800F0E40_ovl05
#undef D_800F5374_ovl05

#define D_8007BD4C D_800F9A4C_ovl03

#define func_800532E0 func_800F1474_ovl03
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F0ED0_ovl05 func_800F14B0_ovl03
#define func_800F0FFC_ovl05 func_800F15DC_ovl03
#define func_800F0EFC_ovl05 func_800F14DC_ovl03
#include "shared/func_800F0ED0_ovl05.c"
#undef func_800F0ED0_ovl05
#undef func_800F0EFC_ovl05
#undef func_800F0FFC_ovl05

#define D_8007BD4C D_800F9A54_ovl03

#define func_800532E0 func_800F1520_ovl03
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F0F7C_ovl05 func_800F155C_ovl03
#define func_800F0FFC_ovl05 func_800F15DC_ovl03
#define func_800F103C_ovl05 func_800F161C_ovl03
#define func_800F0FB0_ovl05 func_800F1590_ovl03
#include "shared/func_800F0F7C_ovl05.c"
#undef func_800F0F7C_ovl05
#undef func_800F0FB0_ovl05
#undef func_800F0FFC_ovl05
#undef func_800F103C_ovl05
