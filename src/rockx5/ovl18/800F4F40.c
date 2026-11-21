#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

#define D_8007BD4C D_800F7DAC_ovl18

#define func_800532E0 func_800F4F40_ovl18
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800EEE74_ovl03 func_800F4F7C_ovl18
#define func_800EEEB8_ovl03 func_800F4FC0_ovl18
#include "shared/func_800EEE74_ovl03.c"
#undef func_800EEE74_ovl03
#undef func_800EEEB8_ovl03
