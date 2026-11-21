#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

#define D_800F5008_ovl05 D_800FD51C_ovl27

#define func_800EF424_ovl05 func_800F6A78_ovl27
#include "shared/func_800EF424_ovl05.c"
#undef func_800EF424_ovl05
#undef D_800F5008_ovl05

#define D_800F4FEC_ovl05 D_800FD500_ovl27
#define D_800F4FF0_ovl05 D_800FD504_ovl27
#define D_800F4FF4_ovl05 D_800FD508_ovl27
#define func_800EF490_ovl05 func_800F6AE4_ovl27
#define func_800EF570_ovl05 func_800F6BC4_ovl27
#include "shared/func_800EF490_ovl05.c"
#undef func_800EF490_ovl05
#undef D_800F4FEC_ovl05
#undef D_800F4FF0_ovl05
#undef D_800F4FF4_ovl05
#undef func_800EF570_ovl05

#define D_800EEBA0_ovl00 func_800F6CAC_ovl27
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F6CCC_ovl27
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
