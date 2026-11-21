#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"

#define D_8007BD4C D_800FDC44_ovl37

#define func_800532E0 func_800FD580_ovl37
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F8584_ovl11 func_800FD5BC_ovl37
#define func_800F85BC_ovl11 func_800FD5F4_ovl37
#include "shared/func_800F8584_ovl11.c"
#undef func_800F8584_ovl11
#undef func_800F85BC_ovl11

#define D_800EEC60_ovl00 func_800FD640_ovl37
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
