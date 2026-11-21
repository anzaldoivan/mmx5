#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#define D_800EEBA0_ovl00 func_800F129C_ovl14
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800F20C8_ovl12 D_800F206C_ovl14
#define func_800F12BC_ovl12 func_800F12BC_ovl14
#define func_800F13BC_ovl12 func_800F13BC_ovl14
#include "shared/func_800F12BC_ovl12.c"
#undef func_800F12BC_ovl12
#undef D_800F20C8_ovl12
#undef func_800F13BC_ovl12

#define D_800EEBA0_ovl00 func_800F1460_ovl14
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800F1480_ovl12 func_800F1480_ovl14
#define D_800F20CC_ovl12 D_800F2070_ovl14
#define func_800F1554_ovl12 func_800F1554_ovl14
#include "shared/func_800F1480_ovl12.c"
#undef func_800F1480_ovl12
#undef func_800F1554_ovl12
#undef D_800F20CC_ovl12

#define D_800EEBA0_ovl00 func_800F1608_ovl14
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
