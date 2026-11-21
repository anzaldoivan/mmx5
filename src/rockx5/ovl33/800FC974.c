#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl33.h"
#include "mmx5/ovl06.h"

#define func_800F9E58_ovl06 func_800FC974_ovl33
#include "shared/func_800F9E58_ovl06.c"
#undef func_800F9E58_ovl06

#define func_800FA400_ovl06 func_800FC9C4_ovl33
#define func_800F9180_ovl06 func_800FB744_ovl33
#define func_800FA4D8_ovl06 func_800FCA9C_ovl33
#include "shared/func_800FA400_ovl06.c"
#undef func_800FA400_ovl06
#undef func_800FA4D8_ovl06
