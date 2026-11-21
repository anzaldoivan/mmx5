#include "types.h"
#include "addr.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F5C88_ovl27(u8* arg0) {
    arg0[5] = D_1F80004C.bytes[0x89];
}

extern u8 D_800FD460_ovl27[];
extern u8 D_800FD464_ovl27[];
extern u8 D_800FD468_ovl27[];
extern u8 D_800FD46C_ovl27[];

void func_800F5CA0_ovl27(ObjF5CA0* arg0) {
    arg0->unk60 = 8;
    arg0->unk5C = 0;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    arg0->unk16 = 4;
    arg0->unk67 = 1;
    arg0->unk54 = 0;
    switch (arg0->unk2) {
    case 0:
        set_animation(arg0, 5);
        if (arg0->unk15 == 0) {
            arg0->unk20 = -0x40000;
        } else {
            arg0->unk20 = 0x40000;
        }
        arg0->unk24 = 0;
        arg0->unk50 = D_800FD460_ovl27;
        arg0->unk68 = D_800FD464_ovl27;
        break;
    case 1:
        set_animation(arg0, 6);
        if (arg0->unk15 == 0) {
            arg0->unk20 = -0x40000;
        } else {
            arg0->unk20 = 0x40000;
        }
        arg0->unk24 = -0x40000;
        arg0->unk50 = D_800FD468_ovl27;
        arg0->unk68 = D_800FD46C_ovl27;
        break;
    }
    arg0->unk4 = 1;
    arg0->unk6 = 0;
    arg0->unk7 = 0;
    arg0->unk3 = 0;
}

extern u8 D_8009A197;
s32 func_8004FC64(u8* a0);

void func_800F5DA4_ovl27(u8* a0) {
    if (D_8009A197 == 0) {
        animate_object();
        move_object(a0);
    }
    func_800317B8(a0);
    if (a0[0x70] != 0) {
        goto block;
    }
    ((s32(*)())func_8002F8FC)(a0);
    if (a0[0x70] != 0) {
    block:
        func_8004FC64(a0);
        a0[4]++;
        return;
    }
    if (is_off_screen(a0, 0x20, 0x20) == 0) {
        func_8002D9EC(a0, 0x10, 0x10);
        return;
    }
    a0[4]++;
}
