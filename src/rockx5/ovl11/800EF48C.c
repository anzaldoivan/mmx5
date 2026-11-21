#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern u8 D_800F9614_ovl11[];

void func_800EF48C_ovl11(Obj800EF48C* arg0) {
    arg0->unk3 = 0;
    arg0->unk4 = 1;
    arg0->unk50 = D_800F9614_ovl11;
    arg0->unk60 = 0x14;
}

void func_800EF4B0_ovl11(u8* a0) {
    func_800317B8(a0);
    a0[4] = 2;
}

#define D_800EEBA0_ovl00 func_800EF4DC_ovl11
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
