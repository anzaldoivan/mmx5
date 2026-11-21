#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "mmx5/ovl18.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

#define func_800F57B4_ovl27 func_800F6388_ovl18
#include "shared/func_800F57B4_ovl27.c"
#undef func_800F57B4_ovl27

#define func_800F5B44_ovl27 func_800F6718_ovl18

#define func_800F5820_ovl27 func_800F63F4_ovl18
#include "shared/func_800F5820_ovl27.c"
#undef func_800F5820_ovl27
#undef func_800F5B44_ovl27

#define D_8007BD4C D_800F80BC_ovl18

#define func_800532E0 func_800F647C_ovl18
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F58E4_ovl27 func_800F64B8_ovl18
#include "shared/func_800F58E4_ovl27.c"
#undef func_800F58E4_ovl27

#define func_800F5B44_ovl27 func_800F6718_ovl18
#define func_800F5950_ovl27 func_800F6524_ovl18
#define func_800F59D8_ovl27 func_800F65AC_ovl18
#include "shared/func_800F5950_ovl27.c"
#undef func_800F5950_ovl27
#undef func_800F5B44_ovl27
#undef func_800F59D8_ovl27

#define func_800F5A88_ovl27 func_800F665C_ovl18
#include "shared/func_800F5A88_ovl27.c"
#undef func_800F5A88_ovl27

#define func_800F5AB4_ovl27 func_800F6688_ovl18
#define func_800F5B44_ovl27 func_800F6718_ovl18
#include "shared/func_800F5AB4_ovl27.c"
#undef func_800F5AB4_ovl27
#undef func_800F5B44_ovl27

#define func_800F5C58_ovl27 func_800F682C_ovl18
#include "shared/func_800F5C58_ovl27.c"
#undef func_800F5C58_ovl27

#define func_800F5C88_ovl27 func_800F685C_ovl18
#define D_800FD460_ovl27 D_800F80C4_ovl18
#define D_800FD464_ovl27 D_800F80C8_ovl18
#define D_800FD468_ovl27 D_800F80CC_ovl18
#define D_800FD46C_ovl27 D_800F80D0_ovl18
#define func_800F5CA0_ovl27 func_800F6874_ovl18
#define func_800F5DA4_ovl27 func_800F6978_ovl18
#include "shared/func_800F5C88_ovl27.c"
#undef func_800F5C88_ovl27
#undef func_800F5CA0_ovl27
#undef D_800FD460_ovl27
#undef D_800FD464_ovl27
#undef D_800FD468_ovl27
#undef D_800FD46C_ovl27
#undef func_800F5DA4_ovl27

#define D_800EEBA0_ovl00 func_800F6A38_ovl18
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
