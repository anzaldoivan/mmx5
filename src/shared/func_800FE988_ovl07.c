#include "types.h"
#include "mmx5/globals.h"

void func_800FE988_ovl07(u8* arg0) {
    *(s16*)(arg0 + 0x90) = 0xB4;
    arg0[6]++;
}

extern void func_800FEBCC_ovl07(EntFE9A0*, s32, s32, s32);

void func_800FE9A0_ovl07(EntFE9A0* e) {
    func_800317B8(e);
    animate_object(e);
    if (--e->timer == -1) {
        func_800FEBCC_ovl07(e, e->x, e->y, 5);
        func_800FEBCC_ovl07(e, e->x, e->y, 6);
        e->state = 2;
    }
}
