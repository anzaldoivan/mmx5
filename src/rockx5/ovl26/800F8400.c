#include "types.h"
#include "addr.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define func_800F5C88_ovl27 func_800F8400_ovl26
#define D_800FD460_ovl27 D_800FA618_ovl26
#define D_800FD464_ovl27 D_800FA61C_ovl26
#define D_800FD468_ovl27 D_800FA620_ovl26
#define D_800FD46C_ovl27 D_800FA624_ovl26
#define func_800F5CA0_ovl27 func_800F8418_ovl26
#define func_800F5DA4_ovl27 func_800F851C_ovl26
#include "shared/func_800F5C88_ovl27.c"
#undef func_800F5C88_ovl27
#undef func_800F5CA0_ovl27
#undef D_800FD460_ovl27
#undef D_800FD464_ovl27
#undef D_800FD468_ovl27
#undef D_800FD46C_ovl27
#undef func_800F5DA4_ovl27

#define D_800EEBA0_ovl00 func_800F85DC_ovl26
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
