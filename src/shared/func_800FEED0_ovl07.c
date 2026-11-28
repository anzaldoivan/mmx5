#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"

extern void start_pad_vibration(s32);

void func_800FEED0_ovl07(u8* obj) {
    s32 d;

    obj[0x16] = 4;
    switch ((s8)obj[2]) {
    case 0:
        start_pad_vibration(2);
        set_animation(obj, 0x17);
        obj[0x15] = 0;
        d = (u8)(((u32(*)())random_byte)() % 48) + 0xFFE8;
        *(u16*)(obj + 0xA) += d;
        if (D_800D1C0C.s != 0xC) {
            *(s16*)(obj + 0xE) = 0x480;
        } else {
            *(s16*)(obj + 0xE) = 0x40;
        }
        obj[4] = 3;
        break;
    case 1:
        set_animation(obj, 1);
        obj[4] = 1;
        break;
    case 2:
        set_animation(obj, 3);
        obj[4] = 1;
        break;
    }
    obj[6] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
}

void func_800FEFEC_ovl07(EntFEFEC* self) {
    ParentFEFEC* parent = self->parent;

    if (parent->unk4 == 2 || parent->unk92 == 0) {
        self->unk4 = 2;
        self->unk3 = 0;
    } else {
        self->unk15 = parent->unk15;
        self->unkA = parent->unkA;
        self->unkE = parent->unkE;
        animate_object(self);
        self->unk3 = 1;
    }
}
