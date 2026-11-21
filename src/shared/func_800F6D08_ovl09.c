#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern u8 D_800FB0B8_ovl09[];

void func_800F6D08_ovl09(Ent6B44* e) {
    Ent6B44* p;

    p = e->unk7C;
    e->unk40 = p->unk40;
    e->unk42 = p->unk42 & 0x7FFF;
    e->unk30 = D_800FB0B8_ovl09;
    e->unk3C = p->unk3C;
    e->unk14 = 0;
    e->unk16 = 1;
    e->unk15 = p->unk15;
    e->unk67 = 0;
    e->unk3 = 0;
    e->unk68 = 0;
    e->unk50 = 0;
    e->unk54 = 0;
    e->unk58 = 0;
    e->unk20 = 0;
    e->unk24 = 0;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk5C = 0;
    e->unk60 = 0;
    set_animation(e, 7);
    e->unk5 = 0;
    e->unk4++;
}

void func_800F6DB8_ovl09(Ent6BF4* e) {
    Ent6BF4* p;

    p = e->unk7C;
    e->unkA = p->unkA;
    e->unkE = p->unkE;
    switch (e->unk5) {
    case 0:
        if (p->unk45 == 1) {
            set_animation(e, 7);
            e->unk5++;
        }
        break;
    case 1:
        if (e->unk46 == 0) {
            e->unk4++;
        }
        func_8002D9EC(e, 0x20, 0x20);
        break;
    }
    p = e->unk7C;
    if (p->unk5 == 11 || p->unk4 == 2) {
        e->unk4++;
    }
    animate_object(e);
    apply_object_motion(e);
}
