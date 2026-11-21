#include "types.h"
#include "mmx5/ovl18.h"
#include "mmx5/object.h"

extern void (*D_800F7F9C_ovl18[])(Obj5B40*);

void func_800F5B40_ovl18(Obj5B40* self) {
    if (((Obj5B40*)self->unk14)->unk4 == 2) {
        self->unk4 = 2;
    }
    D_800F7F9C_ovl18[self->unk4](self);
}

extern u8 D_800D1C00[];

void func_800F5B98_ovl18(u8* obj) {
    D_800D1C00[0x10D] = 0;
    D_800D1C00[0x10E] = 0;
    if (((s8*)D_800D1C00)[0x10] == 2) {
        func_800F5C70_ovl18(1);
        obj[4]++;
    }
}

extern u8 D_800D1C00[];

void func_800F5BEC_ovl18(u8* arg0) {
    D_800D1C00[0x10D] = 1;
    D_800D1C00[0x10E] = 1;
    if (((signed char*)D_800D1C00)[0x10] == 0) {
        func_800F5C70_ovl18(0);
        arg0[4]--;
    }
}

void func_800F5C40_ovl18(u8* obj) {
    func_800F5C70_ovl18(0);
    clear_object_slot(obj);
}

extern u8 D_800D1C00[];

void func_800F5C70_ovl18(s32 a0) {
    u8 arg0 = a0;

    D_800D1C00[0x11] = arg0;
    D_800D1C00[0x14] = arg0;
    D_800D1C00[0x16] = arg0;
    D_800D1C00[0x17] = arg0;
}
