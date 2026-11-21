#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800F2230_ovl08(Obj2230* a0) {
    Obj2230* src = a0->unk7C;

    a0->unk60 = 0x10;
    a0->unk50 = src->unk50;
    a0->unkA = src->unkA;
    a0->unkE = src->unkE;
    a0->unk3 = 0;
    a0->unk4++;
}

void func_800F2270_ovl08(u8* a0) {
    u8* p = *(u8**)(a0 + 0x7C);

    if (*(s8*)(p + 4) == 2) {
        a0[4]++;
    }
    *(u16*)(a0 + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(a0 + 0xE) = *(u16*)(p + 0xE);
    func_800317B8(a0);
}

#define D_800EEBA0_ovl00 func_800F22C8_ovl08
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
