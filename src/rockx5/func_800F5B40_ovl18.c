#include "types.h"

typedef struct Obj5B40 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ signed char unk4;
    /* 0x05 */ u8 pad5[0x14 - 0x5];
    /* 0x14 */ void* unk14; /* an Obj5B40 */
} Obj5B40;

extern void (*D_800F7F9C_ovl18[])(Obj5B40*);

void func_800F5B40_ovl18(Obj5B40* self) {
    if (((Obj5B40*)self->unk14)->unk4 == 2) {
        self->unk4 = 2;
    }
    D_800F7F9C_ovl18[self->unk4](self);
}
