#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern u8 D_800F4FF4_ovl05[];
extern u8 D_800F4FEC_ovl05[];
extern u8 D_800F4FF0_ovl05[];
extern u8 D_80074E40[];

void func_800EF490_ovl05(Ent6B44* e) {
    Ent6B44* p = e->unk7C;

    e->unk3 = 1;
    e->unk68 = (s32)D_800F4FF4_ovl05;
    e->unk54 = (s32)D_800F4FEC_ovl05;
    e->unk4++;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk67 = 0;
    e->unk16 = 1;
    e->unk50 = (s32)D_800F4FF0_ovl05;
    e->unk58 = (s32)D_80074E40;
    e->unk40 = p->unk40;
    e->unk42 = p->unk42 & 0x7FFF;
    e->unk30 = p->unk30;
    e->unk3C = p->unk3C;
    e->unk15 = p->unk15;
    e->unk14 = p->unk14;
    e->unk5C = 1;
    e->unk60 = 3;
    e->unk20 <<= 1;
    e->unk24 <<= 1;
    set_animation(e, 0xF);
}

extern u8 D_8009A197;
s32 func_8004FC64(u8* a0);

void func_800EF570_ovl05(u8* a0) {
    s32 state;

    if (D_8009A197 == 0) {
        animate_object();
        move_object(a0);
    }
    if (func_800317B8(a0) != 0) {
        state = 2;
        goto store;
    }
    if (func_80031DD0(a0) < 0) {
        ((s32(*)())func_8004FD24)(a0);
        a0[4]++;
        return;
    } else {
        if (a0[0x70] == 0) {
            ((s32(*)())func_8002F8FC)(a0);
            if (a0[0x70] == 0) {
                goto check;
            }
        }
        func_8004FC64(a0);
    }
    a0[4]++;
    return;
check:
    if (is_off_screen(a0, 0x20, 0x20) == 0) {
        func_8002D9EC(a0, 0x10, 0x10);
        return;
    }
    state = a0[4] + 1;
store:
    a0[4] = state;
}
