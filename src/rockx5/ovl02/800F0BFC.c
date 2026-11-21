#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "addr.h"

#define D_800F96CC_ovl03 D_800F4608_ovl02
#define D_800F96D0_ovl03 D_800F460C_ovl02
#define func_800EFDEC_ovl03 func_800F0BFC_ovl02
#define func_800EFE78_ovl03 func_800F0C88_ovl02
#include "shared/func_800EFDEC_ovl03.c"
#undef func_800EFDEC_ovl03
#undef D_800F96CC_ovl03
#undef D_800F96D0_ovl03
#undef func_800EFE78_ovl03

#define D_800EEBA0_ovl00 func_800F0D84_ovl02
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F0DA4_ovl02
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#include "shared/func_800F0DAC_ovl02.c"

#include "shared/func_800F1274_ovl02.c"

#define D_800F4844_ovl05 D_800F471C_ovl02

#define func_800EEA80_ovl05 func_800F25D0_ovl02
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define D_800F4844_ovl05 D_800F47A0_ovl02

#define func_800EEA80_ovl05 func_800F260C_ovl02
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
