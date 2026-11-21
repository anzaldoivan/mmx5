#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/globals.h"
#include "mmx5/ovl00.h"
#include "mmx5/movement.h"
#include "mmx5/title.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/object.h"

#include "shared/func_800F292C_ovl00.c"

#define D_800F75FC_ovl18 D_800FAD80_ovl00
#define animate_object func_800F2FC8_ovl00
#define func_8002D89C func_800F2CE4_ovl00

#define func_800EF750_ovl18 func_800F2A18_ovl00
#include "shared/func_800EF750_ovl18.c"
#undef func_800EF750_ovl18
#undef D_800F75FC_ovl18
#undef animate_object
#undef func_8002D89C

#include "shared/func_800F2A6C_ovl00.c"

#define func_800F28B4_ovl00 func_800F2AB0_ovl00
#include "shared/func_800F28B4_ovl00.c"
#undef func_800F28B4_ovl00

#define D_8007BD4C D_800FAD88_ovl00

#define func_800532E0 func_800F2AEC_ovl00
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F2B28_ovl00.c"

#define D_8007BD4C D_800FAD98_ovl00

#define func_800532E0 func_800F2C30_ovl00
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F2C6C_ovl00.c"

extern void func_800F2038_ovl00();
#define D_800EEBA0_ovl00 func_800F2CC4_ovl00
#define func_8002D720 func_800F2038_ovl00
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#include "shared/func_800F2CE4_ovl00.c"

#define D_800F4844_ovl05 D_800FADBC_ovl00

#define func_800EEA80_ovl05 func_800F3524_ovl00
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#include "shared/func_800F3560_ovl00.c"

#define D_800EEBA0_ovl00 func_800F360C_ovl00
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
