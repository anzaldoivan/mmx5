#include "types.h"

extern D_8009A1F8_5E_t D_8009A1F8;
extern void (*D_80102E5C_ovl04[])(u8*);
extern u16 D_80103090_ovl04;
extern u16 D_80103092_ovl04;

void func_800FF4D0_ovl04(u8* p) {
    u8 t;
    D_8009A1F8_5E_t* b;

    D_80102E5C_ovl04[(s8)p[2]](p);
    t = p[2];
    if (t < 2 || (s8)t == 9 || (s8)t == 0x10) {
        if (*(u16*)(p + 0x42) & 0x8000) {
            b = &D_8009A1F8;
            b->unk5E = D_80103090_ovl04 - *(u16*)(p + 0xA);
            b->unk62 = D_80103092_ovl04 - *(u16*)(p + 0xE) + 0x500;
        } else {
            b = &D_8009A1F8;
            b->unk5E = D_80103090_ovl04 - *(u16*)(p + 0xA);
            b->unk62 = D_80103092_ovl04 - *(u16*)(p + 0xE);
        }
    }
}
