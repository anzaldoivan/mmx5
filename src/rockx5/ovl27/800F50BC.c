#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/graphics.h"

#include "shared/func_800F50BC_ovl27.c"

#define D_800F4844_ovl05 D_800FD410_ovl27

#define func_800EEA80_ovl05 func_800F5290_ovl27
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define D_800F4844_ovl05 D_800FD470_ovl27

#define func_800EEA80_ovl05 func_800F52CC_ovl27
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#include "shared/func_800F5308_ovl27.c"

#define D_800EEBA0_ovl00 func_800F5424_ovl27
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800F5444_ovl27
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#include "shared/func_800F5464_ovl27.c"

#define D_800FA778_ovl09 D_800FD43C_ovl27

void func_800F5A88_ovl27(X4_Obj*);
#define func_800EF37C_ovl09 func_800F54DC_ovl27
#define animate_object func_800F5A88_ovl27
#include "shared/func_800EF37C_ovl09.c"
#undef func_800EF37C_ovl09
#undef animate_object
