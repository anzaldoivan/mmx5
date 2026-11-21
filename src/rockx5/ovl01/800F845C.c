#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800F845C_ovl01(Ent2CE8* arg0) {
    Ent2CE8* parent = arg0->unk7C;

    arg0->unk60 = 0x7F;
    arg0->unk50 = parent->unk50;
    arg0->unk15 = parent->unk15;
    arg0->unkA = parent->unkA;
    arg0->unkE = parent->unkE;
    arg0->unk3 = 0;
    arg0->unk4++;
}

void func_800F84A4_ovl01(u8* obj) {
    u8* p = *(u8**)(obj + 0x7C);

    if ((u8)(p[4] - 2) < 2) {
        obj[4]++;
    }
    obj[0x15] = p[0x15];
    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    func_800317B8(obj);
}

#define D_800EEBA0_ovl00 func_800F8510_ovl01
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
