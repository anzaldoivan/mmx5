#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define D_800FA78C_ovl00 D_800FCAC8_ovl27
#define func_800F01AC_ovl00 func_800F0FD0_ovl27
#define func_800F02D0_ovl00 func_800F10F4_ovl27
#include "shared/func_800F01AC_ovl00.c"
#undef func_800F01AC_ovl00
#undef D_800FA78C_ovl00
#undef func_800F02D0_ovl00

#define D_8007BD4C D_800FCC18_ovl27

#define func_800532E0 func_800F11DC_ovl27
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F03F4_ovl00 func_800F1218_ovl27
#define func_800F0418_ovl00 func_800F123C_ovl27
#define func_800F0494_ovl00 func_800F12B8_ovl27
#include "shared/func_800F03F4_ovl00.c"
#undef func_800F03F4_ovl00
#undef func_800F0418_ovl00
#undef func_800F0494_ovl00

#define func_800F04E8_ovl00 func_800F130C_ovl27
#include "shared/func_800F04E8_ovl00.c"
#undef func_800F04E8_ovl00

#define D_8007BD4C D_800FCC28_ovl27

#define func_800532E0 func_800F137C_ovl27
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F03F4_ovl00 func_800F13B8_ovl27
#define func_800F0418_ovl00 func_800F13DC_ovl27
#define func_800F0494_ovl00 func_800F1458_ovl27
#include "shared/func_800F03F4_ovl00.c"
#undef func_800F03F4_ovl00
#undef func_800F0418_ovl00
#undef func_800F0494_ovl00

#define func_800F0688_ovl00 func_800F14AC_ovl27
#include "shared/func_800F0688_ovl00.c"
#undef func_800F0688_ovl00
