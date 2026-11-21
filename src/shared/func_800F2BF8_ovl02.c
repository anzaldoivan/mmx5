#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"

void func_800F2BF8_ovl02(Ent2BF8* a0) {
    if (a0->unk70 & 8) {
        *(s32*)((u8*)a0 + 0x2C) = 0;
        *(s32*)((u8*)a0 + 0x24) = 0;
        if (a0->unkA < D_8009A0AA) {
            a0->unk20 = 0x38000;
            a0->unk5 = 3;
        } else {
            a0->unk20 = -0x38000;
            a0->unk5 = 7;
        }
    }
    apply_object_motion(a0);
}

void func_800F2C70_ovl02(Ent2BF8* a0) {
    if (a0->unk70 & 4) {
        *(s32*)((u8*)a0 + 0x2C) = 0;
        *(s32*)((u8*)a0 + 0x24) = 0;
        if (a0->unkA < D_8009A0AA) {
            a0->unk20 = 0x38000;
            a0->unk5 = 9;
        } else {
            a0->unk20 = -0x38000;
            a0->unk5 = 5;
        }
    }
    apply_object_motion(a0);
}

void func_800F2CE8_ovl02(Ent2CE8* arg0) {
    Ent2CE8* parent = arg0->unk7C;

    arg0->unk60 = 4;
    arg0->unk50 = parent->unk50;
    arg0->unk15 = parent->unk15;
    arg0->unkA = parent->unkA;
    arg0->unkE = parent->unkE;
    arg0->unk3 = 0;
    arg0->unk4++;
}

void func_800F2D30_ovl02(u8* obj) {
    u8* p = *(u8**)(obj + 0x7C);

    if (((signed char*)p)[4] == 6) {
        obj[4]++;
    }
    obj[0x15] = p[0x15];
    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    func_800317B8(obj);
}
