#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"

#define D_800FA214_ovl00 D_800FAE78_ovl09

#define func_800EEB64_ovl00 func_800F6540_ovl09
#include "shared/func_800EEB64_ovl00.c"
#undef func_800EEB64_ovl00
#undef D_800FA214_ovl00

#include "shared/func_800F657C_ovl09.c"

#define func_800F0D00_ovl12 func_800F6600_ovl09
#include "shared/func_800F0D00_ovl12.c"
#undef func_800F0D00_ovl12

#include "shared/func_800F6700_ovl09.c"

#define D_800FFBC0_ovl35 D_800FB0B8_ovl09
#define func_800FECE4_ovl35 func_800F67D8_ovl09
#include "shared/func_800FECE4_ovl35.c"
#undef func_800FECE4_ovl35
#undef D_800FFBC0_ovl35

#define D_800EEBA0_ovl00 func_800F6964_ovl09
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
