#include "types.h"

typedef struct Obj800FC038 {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ s8 unk3;
    /* 0x04 */ s8 unk4;
    /* 0x05 */ s8 unk5;
    /* 0x06 */ u8 pad6[0x50 - 0x6];
    /* 0x50 */ void* unk50;
} Obj800FC038;

extern void (*D_800FF73C_ovl06[])(Obj800FC038*);

void func_800FC038_ovl06(Obj800FC038* self) {
    if (((Obj800FC038*)self->unk50)->unk4 == 2) {
        self->unk4 = 2;
        self->unk3 = 0;
    } else {
        D_800FF73C_ovl06[self->unk5](self);
    }
}
