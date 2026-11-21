#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern u8 D_800FFBC0_ovl35[];
extern u8 D_80074DA0[];

void func_800FECE4_ovl35(Ent6B44* e) {
    Ent6B44* p;

    p = e->unk7C;
    e->unk40 = p->unk40;
    e->unk42 = p->unk42 & 0x7FFF;
    e->unk30 = D_800FFBC0_ovl35;
    e->unk3C = p->unk3C;
    e->unk14 = 0;
    e->unk16 = 1;
    e->unk67 = 0;
    e->unk3 = 0;
    e->unk68 = 0;
    e->unk50 = 0;
    e->unk54 = 0;
    e->unk58 = (s32)D_80074DA0;
    e->unk20 = 0;
    e->unk24 = 0;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk5C = 0;
    e->unk60 = 0;
    set_animation(e, 0);
    e->unk5 = 0;
    e->unk4++;
}

void func_800F6888_ovl09(u8* obj) {
    u8* p;

    p = *(u8**)(obj + 0x7C);
    obj[0x15] = p[0x15];
    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    if (*(s8*)(obj + 5) == 0) {
        if (*(s32*)(p + 0x20) == 0) {
            set_animation(obj, 1);
            obj[5] = 1;
        }
    } else if (*(s32*)(p + 0x24) == 0) {
        set_animation(obj, 0);
        obj[5] = 0;
    }
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) == 2) {
        obj[4]++;
    }
    func_8002D9EC(obj, 0x10, 0x10);
    animate_object(obj);
    apply_object_motion(obj);
}
