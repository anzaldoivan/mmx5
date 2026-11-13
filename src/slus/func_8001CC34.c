#include "types.h"

extern u8 D_800D1C00[];
extern u16 D_8006FAE4[];
extern u16 D_80070E7C[];
extern u8 D_8006FADB;
extern void func_80011FD4(s8 arg0, s8 arg1);

void func_8001CC34(D_800E81E4_t8001C904* s) {
    u8 i;
    D_800D1C00_t8001C904* d = (D_800D1C00_t8001C904*)D_800D1C00;

    d->f79 = s->f1;
    d->fA0 = s->f2;
    d->f84 = s->f4;
    for (i = 0; i < 6; i++) {
        d->a88[i] = s->a8[i];
        d->a4D[i] = s->a4B[i];
        d->aA3[i] = s->a52[i];
    }
    d->f80 = s->f20;
    d->f7E = s->f24;
    for (i = 0; i < 16; i++) {
        D_8006FAE4[i] = s->a26[i];
    }
    d->f53 = s->f48;
    d->f54 = s->f49;
    d->f47 = s->f46;
    d->f48 = s->f47;
    d->f4C = s->f4A;
    d->f4B = s->f51;
    d->f4A = s->f58;
    d->fA1 = s->f59;
    if (s->f24 & D_80070E7C[3]) {
        d->f45 = 4;
    } else {
        d->f45 = 2;
    }
    d->f76 = 0;
    d->f77 = 0;
    d->f78 = 0;
    d->fA9 = s->f5A;
    d->fAA = s->f5B;
    d->fAB = s->f5C;
    d->fAC = s->fE0;
    d->f1B4 = s->fE4;
    for (i = 0; i < 4; i++) {
        d->aC2[i] = s->aE8[i];
        d->aC6[i] = s->aEC[i];
    }
    d->fCA = s->fF0;
    d->fCB = s->fF1;
    d->f10F = s->f5D;
    d->f110 = s->f5E;
    D_8006FADB = s->f5E;
    d->f1BA = s->f5F;
    for (i = 0; i < 32; i++) {
        d->a114[i] = s->a60[i];
        d->a194[i] = s->a132[i];
        d->aCD[i] = s->aF2[i];
        d->aED[i] = s->a112[i];
    }
    d->f1B8 = s->f152;
    d->f1B9 = s->f153;
    func_80011FD4(d->f1B8, d->f1B9);
    if (s->f58 & 1) {
        d->f44 = 0;
    } else {
        d->f44 = 1;
    }
}
