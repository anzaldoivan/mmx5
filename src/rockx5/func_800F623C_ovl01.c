#include "types.h"

extern void (*D_800FD21C_ovl01[])(X4_Obj*);
extern s8 D_800D1C1D;

void func_800F623C_ovl01(X4_Obj* self) {
    D_800FD21C_ovl01[self->state](self);
    if (D_800D1C1D == 3) {
        self->state = 6;
    }
}
