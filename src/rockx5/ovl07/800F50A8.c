#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800EEBA0_ovl00 func_800F50A8_ovl07
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800F50C8_ovl07
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800F2688_ovl02 func_800F50E8_ovl07
#include "shared/func_800F2688_ovl02.c"
#undef func_800F2688_ovl02

#define D_800EEBA0_ovl00 func_800F5164_ovl07
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
