#include "types.h"

extern u8 D_8009A0A0[];
extern void (*D_800771A8[])(Ent8004A364*);

void func_8004A364(Ent8004A364* e) {
    s32 f = (s8)D_8009A0A0[0xD3] != 0;

    if ((s8)D_8009A0A0[0xD4] != 0) {
        f = 1;
    }
    if ((s8)D_8009A0A0[0x93] != 7) {
        f = 1;
    }
    if ((s8)D_8009A0A0[0x96] == 0x10) {
        f = 1;
    }
    if (f) {
        e->state = 3;
    }
    D_800771A8[e->state](e);
}
