#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "addr.h"

#define D_8007BD4C D_800FDBF8_ovl37

#define func_800532E0 func_800FCBB0_ovl37
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F81F4_ovl11 func_800FD22C_ovl37
#define func_800F7BB4_ovl11 func_800FCBEC_ovl37
#define D_800FA060_ovl11 D_800FDC94_ovl37
#define func_800F7C34_ovl11 func_800FCC6C_ovl37
#define D_800F9D10_ovl11 D_800FD944_ovl37
#define D_800F9D14_ovl11 D_800FD948_ovl37
#define func_800F7CDC_ovl11 func_800FCD14_ovl37
#include "shared/func_800F7BB4_ovl11.c"
#undef func_800F7BB4_ovl11
#undef func_800F81F4_ovl11
#undef func_800F7C34_ovl11
#undef D_800FA060_ovl11
#undef func_800F7CDC_ovl11
