#include "types.h"

// from rockx5 800F1344: scratchpad context, signed count at 0x82
typedef struct Scr1344 {
    /* 0x00 */ u8 pad0[0x82];
    /* 0x82 */ signed char unk82;
} Scr1344;

#define D_1F80004C (*(Scr1344**)0x1F80004C)

void func_800F0B70_ovl28();

void func_800F1344_ovl28(Obj* arg0) {
    if (D_1F80004C->unk82 < 9) {
        func_800F0B70_ovl28();
        arg0->step -= 2;
    } else {
        arg0->step++;
    }
}
