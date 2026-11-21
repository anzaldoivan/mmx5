#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800F96CC_ovl03 D_800FF754_ovl06
#define D_800F96D0_ovl03 D_800FF758_ovl06
#define func_800EFDEC_ovl03 func_800FC4E8_ovl06
#define func_800EFE78_ovl03 func_800FC574_ovl06
#include "shared/func_800EFDEC_ovl03.c"
#undef func_800EFDEC_ovl03
#undef D_800F96CC_ovl03
#undef D_800F96D0_ovl03
#undef func_800EFE78_ovl03

#define D_800EEBA0_ovl00 func_800FC670_ovl06
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800FC690_ovl06
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
