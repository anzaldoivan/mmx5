#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#include "shared/func_800EEB64_ovl03.c"

#include "shared/func_800EECC0_ovl03.c"

#include "shared/func_800EED0C_ovl03.c"

#define D_800EEBA0_ovl00 func_800EEDF8_ovl03
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800EEE18_ovl03
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
