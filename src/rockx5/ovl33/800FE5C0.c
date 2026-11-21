#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

#define D_800F4844_ovl05 D_800FF02C_ovl33

#define func_800EEA80_ovl05 func_800FE5C0_ovl33
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define D_800FF73C_ovl06 D_800FF03C_ovl33

#define func_800FC038_ovl06 func_800FE5FC_ovl33
#include "shared/func_800FC038_ovl06.c"
#undef func_800FC038_ovl06
#undef D_800FF73C_ovl06

#define D_800EEBA0_ovl00 func_800FE65C_ovl33
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800FF748_ovl06 D_800FF048_ovl33
#define func_800FC0B8_ovl06 func_800FE67C_ovl33
#define func_800FC1C0_ovl06 func_800FE784_ovl33
#define D_800FF744_ovl06 D_800FF044_ovl33
#define func_800FC26C_ovl06 func_800FE830_ovl33
#include "shared/func_800FC0B8_ovl06.c"
#undef func_800FC0B8_ovl06
#undef D_800FF748_ovl06
#undef func_800FC1C0_ovl06
#undef func_800FC26C_ovl06
