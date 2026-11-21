#include "types.h"
#include "mmx5/object.h"

void func_800F1544_ovl04(Ent800FE04C* e) {
    e->unk6++;
    e->unk20 = 0x30000;
    *(s16*)((u8*)e + 0x7C) = 0x28;
}

void func_800F1564_ovl04(Ent1564* self) {
    if (--self->timer == -1) {
        self->field16 = 3;
        self->state = 7;
        self->sub = 0;
        return;
    }
    move_object(self);
}

extern u8* func_8002C938();

void func_800F15B8_ovl04(u8* o, s32 a1) {
    u8 arg1 = a1;
    u8* c;

    c = func_8002C938();
    if (c != 0) {
        c[0] = 0x41;
        c[1] = 3;
        c[2] = arg1;
        *(u16*)(c + 0xA) = *(u16*)(o + 0xA);
        *(u16*)(c + 0xE) = *(u16*)(o + 0xE);
        c[0x15] = o[0x15];
    }
}
