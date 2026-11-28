#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#define D_8007BD4C D_800F7CC8_ovl18

#define func_800532E0 func_800F4C30_ovl18
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define D_800F956C_ovl03 D_800F7D84_ovl18
#define D_800F9580_ovl03 D_800F7D98_ovl18
#define func_800EF04C_ovl03 func_800F5154_ovl18

#define func_800EEB64_ovl03 func_800F4C6C_ovl18
#include "shared/func_800EEB64_ovl03.c"
#undef func_800EEB64_ovl03
#undef D_800F956C_ovl03
#undef D_800F9580_ovl03
#undef func_800EF04C_ovl03

#define D_800F9570_ovl03 D_800F7D88_ovl18

#define func_800EECC0_ovl03 func_800F4DC8_ovl18
#include "shared/func_800EECC0_ovl03.c"
#undef func_800EECC0_ovl03
#undef D_800F9570_ovl03

#define func_800EED0C_ovl03 func_800F4E14_ovl18
#define D_800F94D0_ovl03 D_800F7CE8_ovl18
#define D_800F94D4_ovl03 D_800F7CEC_ovl18
#define D_800F94D8_ovl03 D_800F7CF0_ovl18
#define D_800F9554_ovl03 D_800F7D6C_ovl18
#include "shared/func_800EED0C_ovl03.c"
#undef func_800EED0C_ovl03
#undef D_800F94D0_ovl03
#undef D_800F94D4_ovl03
#undef D_800F94D8_ovl03
#undef D_800F9554_ovl03

#define D_800EEBA0_ovl00 func_800F4F00_ovl18
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800F4F20_ovl18
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
