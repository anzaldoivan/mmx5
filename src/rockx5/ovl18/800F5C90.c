#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/graphics.h"

#define D_800FD344_ovl27 D_800F7FA8_ovl18
#define D_800FD348_ovl27 D_800F7FAC_ovl18
#define D_800FD34C_ovl27 D_800F7FB0_ovl18
#define D_800FD350_ovl27 D_800F7FB4_ovl18
#define D_800FD408_ovl27 D_800F806C_ovl18
#define D_800FD424_ovl27 D_800F8088_ovl18
#define func_800F5AB4_ovl27 func_800F6688_ovl18

#define func_800F50BC_ovl27 func_800F5C90_ovl18
#include "shared/func_800F50BC_ovl27.c"
#undef func_800F50BC_ovl27
#undef D_800FD344_ovl27
#undef D_800FD348_ovl27
#undef D_800FD34C_ovl27
#undef D_800FD350_ovl27
#undef D_800FD408_ovl27
#undef D_800FD424_ovl27
#undef func_800F5AB4_ovl27

#define D_800F4844_ovl05 D_800F8074_ovl18

#define func_800EEA80_ovl05 func_800F5E64_ovl18
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define D_800F4844_ovl05 D_800F80D4_ovl18

#define func_800EEA80_ovl05 func_800F5EA0_ovl18
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define D_800FD344_ovl27 D_800F7FA8_ovl18
#define D_800FD348_ovl27 D_800F7FAC_ovl18
#define D_800FD3D8_ovl27 D_800F803C_ovl18
#define func_800F5C58_ovl27 func_800F682C_ovl18

#define func_800F5308_ovl27 func_800F5EDC_ovl18
#include "shared/func_800F5308_ovl27.c"
#undef func_800F5308_ovl27
#undef D_800FD344_ovl27
#undef D_800FD348_ovl27
#undef D_800FD3D8_ovl27
#undef func_800F5C58_ovl27

#define D_800EEBA0_ovl00 func_800F5FF8_ovl18
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800F6018_ovl18
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800F5464_ovl27 func_800F6038_ovl18
#include "shared/func_800F5464_ovl27.c"
#undef func_800F5464_ovl27

#define D_800FA778_ovl09 D_800F80A0_ovl18

void func_800F665C_ovl18(X4_Obj*);
#define func_800EF37C_ovl09 func_800F60B0_ovl18
#define animate_object func_800F665C_ovl18
#include "shared/func_800EF37C_ovl09.c"
#undef func_800EF37C_ovl09
#undef animate_object
