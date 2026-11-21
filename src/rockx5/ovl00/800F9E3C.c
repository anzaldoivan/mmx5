#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern u8 D_800FB650_ovl00[];

void func_800F9E3C_ovl00(Obj9D50* self) {
    Obj9D50* p = self->parent;

    self->unk40 = p->unk40;
    self->unk42 = p->unk42 & 0x7FFF;
    self->unk30 = D_800FB650_ovl00;
    self->unk3C = p->unk3C;
    self->unk14 = 0;
    self->unk16 = 0x10;
    self->unk15 = 0;
    self->unk67 = 0;
    self->unk3 = 1;
    self->unk68 = 0;
    self->unk50 = 0;
    self->unk54 = 0;
    self->unk58 = 0;
    self->unkA = p->unkA - 0xA8;
    self->unkE = 0x144;
    self->unk5C = 1;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk2C = 0;
    self->unk60 = 8;
    set_animation(self, 0);
    self->state++;
}

void func_800F9EFC_ovl00(u8* obj) {
    if (*(s8*)(*(u8**)(obj + 0x7C) + 7) == 2) {
        obj[4]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_800317B8(obj);
    if (is_off_screen(obj, 0x20, 0x20) == 0) {
        func_8002D9EC(obj, 0x10, 0x10);
    } else {
        obj[4]++;
    }
}

#define D_800EEBA0_ovl00 func_800F9F98_ovl00
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F9FB8_ovl00
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
