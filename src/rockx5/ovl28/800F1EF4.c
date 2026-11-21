#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/title.h"

#define func_800F17EC_ovl26 func_800F1EF4_ovl28
#include "shared/func_800F17EC_ovl26.c"
#undef func_800F17EC_ovl26

#define D_800F4844_ovl05 D_800FDBBC_ovl28

#define func_800EEA80_ovl05 func_800F1FA4_ovl28
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define D_800F95CC_ovl26 D_800FDBD0_ovl28

#define func_800F18D8_ovl26 func_800F1FE0_ovl28
#include "shared/func_800F18D8_ovl26.c"
#undef func_800F18D8_ovl26
#undef D_800F95CC_ovl26

#define D_800EEBA0_ovl00 func_800F20C8_ovl28
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800F20E8_ovl28
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800F1A00_ovl26 func_800F2108_ovl28
#include "shared/func_800F1A00_ovl26.c"
#undef func_800F1A00_ovl26
