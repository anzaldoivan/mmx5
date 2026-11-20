#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern u8 D_80091C44;
extern D_8009A1F8_t D_8009A1F8;

void func_800FAFE8_ovl50(u8* a0) {
    D_8009A1F8_t* p;

    if (D_80091C44 == 0) {
        p = &D_8009A1F8;
        p->pad0[3] = 0;
        p->unk57 = 0;
        *(u16*)(p->padA1 + 0x11) = 0x200;
        p->unkB6 = 0x400;
        p->padA1[0xA] = 1;
        p->unkF4 = 1;
        *(s16*)(a0 + 4) = 0;
        func_8002385C(0x40, 0xFF, 0);
        play_sound(2, 0x52, 0);
        a0[1]++;
    }
}
