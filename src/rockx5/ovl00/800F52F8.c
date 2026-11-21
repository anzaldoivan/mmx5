#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

#define D_800EEBA0_ovl00 func_800F52F8_ovl00
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F5318_ovl00
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800F4EC0_ovl05 D_800FB104_ovl00

#define func_800EF2C8_ovl05 func_800F5320_ovl00
#include "shared/func_800EF2C8_ovl05.c"
#undef func_800EF2C8_ovl05
#undef D_800F4EC0_ovl05

#define D_8007BD4C D_800FB22C_ovl00

#define func_800532E0 func_800F53AC_ovl00
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define D_800F4FC0_ovl05 D_800FB204_ovl00

#define func_800EF390_ovl05 func_800F53E8_ovl00
#include "shared/func_800EF390_ovl05.c"
#undef func_800EF390_ovl05
#undef D_800F4FC0_ovl05

#define D_800F5008_ovl05 D_800FB24C_ovl00

#define func_800EF424_ovl05 func_800F547C_ovl00
#include "shared/func_800EF424_ovl05.c"
#undef func_800EF424_ovl05
#undef D_800F5008_ovl05

#define D_800F4FEC_ovl05 D_800FB230_ovl00
#define D_800F4FF0_ovl05 D_800FB234_ovl00
#define D_800F4FF4_ovl05 D_800FB238_ovl00
#define func_800EF490_ovl05 func_800F54E8_ovl00
#define func_800EF570_ovl05 func_800F55C8_ovl00
#include "shared/func_800EF490_ovl05.c"
#undef func_800EF490_ovl05
#undef D_800F4FEC_ovl05
#undef D_800F4FF0_ovl05
#undef D_800F4FF4_ovl05
#undef func_800EF570_ovl05

#define D_800EEBA0_ovl00 func_800F56B0_ovl00
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F56D0_ovl00
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
