#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define D_800F98F0_ovl11 D_800FA46C_ovl29
#define D_800F98F8_ovl11 D_800FA474_ovl29
#define func_800F1650_ovl11 func_800F664C_ovl29
#define func_800F1708_ovl11 func_800F6704_ovl29
#include "shared/func_800F1650_ovl11.c"
#undef func_800F1650_ovl11
#undef D_800F98F0_ovl11
#undef D_800F98F8_ovl11
#undef func_800F1708_ovl11

#define D_800EEBA0_ovl00 func_800F67C4_ovl29
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F67E4_ovl29
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
