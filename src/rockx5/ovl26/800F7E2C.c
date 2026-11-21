#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define func_800F56B4_ovl27 func_800F7E2C_ovl26
#include "shared/func_800F56B4_ovl27.c"
#undef func_800F56B4_ovl27

extern void func_800F8150_ovl26(Obj800F2688*);
#define func_800F572C_ovl27 func_800F7EA4_ovl26
#define func_800F59D8_ovl27 func_800F8150_ovl26
#include "shared/func_800F572C_ovl27.c"
#undef func_800F572C_ovl27
#undef func_800F59D8_ovl27

#define D_8007BD4C D_800FA608_ovl26

#define func_800532E0 func_800F7EF0_ovl26
#include "shared/func_800532E0.c"
#undef func_800532E0
