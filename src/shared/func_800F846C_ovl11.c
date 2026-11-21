#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F846C_ovl11(Ent846C* arg0) {
    s32 temp_v1;

    temp_v1 = arg0->unk8;
    arg0->unk54 = 0;
    arg0->unk95 = 0x1E;
    arg0->unk90 = temp_v1;
    arg0->unk8C = temp_v1;
    move_object(arg0);
    arg0->unk54 = 0;
    arg0->unk50 = 0;
    arg0->unk6++;
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

void func_800F84BC_ovl11(Obj800F84BC* p) {
    p->unk8C += 0x10000;
    p->unk90 -= 0x10000;
    // !FAKE: volatile read keeps the global load below the stores (C0194)
    if (!(*(volatile s32*)&D_8009A420_as_s32 & 1)) {
        p->unk8 = p->unk8C;
    } else {
        p->unk8 = p->unk90;
    }
    if (--p->unk95 == 0) {
        p->unk6++;
    }
}

void func_800F8534_ovl11(u8* arg0) {
    (*(u8**)(arg0 + 0x7C))[7] = 0;
    arg0[4] = 2;
}
