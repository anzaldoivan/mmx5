#include "types.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"

#define func_800EFE70_ovl02 func_800F7100_ovl10
#define func_8002D760 clear_object_slot
#include "shared/func_800EFE70_ovl02.c"
#undef func_800EFE70_ovl02
#undef func_8002D760

#include "shared/func_800F7120_ovl10.c"

#define func_800EFE70_ovl02 func_800F7214_ovl10
#define func_8002D760 clear_object_slot
#include "shared/func_800EFE70_ovl02.c"
#undef func_800EFE70_ovl02
#undef func_8002D760

#include "shared/func_800F7234_ovl10.c"

#define func_800EFE70_ovl02 func_800F72A0_ovl10
#define func_8002D760 clear_object_slot
#include "shared/func_800EFE70_ovl02.c"
#undef func_800EFE70_ovl02
#undef func_8002D760

#include "shared/func_800F72C0_ovl10.c"
