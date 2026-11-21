#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

#define D_800EEBA0_ovl00 func_800F1D90_ovl03
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F1DB0_ovl03
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800F4EC0_ovl05 D_800F9B94_ovl03

#define func_800EF2C8_ovl05 func_800F1DB8_ovl03
#include "shared/func_800EF2C8_ovl05.c"
#undef func_800EF2C8_ovl05
#undef D_800F4EC0_ovl05

#define D_8007BD4C D_800F9CBC_ovl03

#define func_800532E0 func_800F1E44_ovl03
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define D_800F4FC0_ovl05 D_800F9C94_ovl03

#define func_800EF390_ovl05 func_800F1E80_ovl03
#include "shared/func_800EF390_ovl05.c"
#undef func_800EF390_ovl05
#undef D_800F4FC0_ovl05

#define D_800F5008_ovl05 D_800F9CDC_ovl03

#define func_800EF424_ovl05 func_800F1F14_ovl03
#include "shared/func_800EF424_ovl05.c"
#undef func_800EF424_ovl05
#undef D_800F5008_ovl05

#define D_800F4FEC_ovl05 D_800F9CC0_ovl03
#define D_800F4FF0_ovl05 D_800F9CC4_ovl03
#define D_800F4FF4_ovl05 D_800F9CC8_ovl03
#define func_800EF490_ovl05 func_800F1F80_ovl03
#define func_800EF570_ovl05 func_800F2060_ovl03
#include "shared/func_800EF490_ovl05.c"
#undef func_800EF490_ovl05
#undef D_800F4FEC_ovl05
#undef D_800F4FF0_ovl05
#undef D_800F4FF4_ovl05
#undef func_800EF570_ovl05

#define D_800EEBA0_ovl00 func_800F2148_ovl03
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F2168_ovl03
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
