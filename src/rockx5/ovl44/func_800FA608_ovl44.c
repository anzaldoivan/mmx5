#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern u8 D_80091C44;

void func_800FA608_ovl44(Ovl45State* arg0) {
    if (D_80091C44 == 0) {
        u8* p;
        play_sound(2, 0x4B, 0);
        p = D_8009A1F8.u;
        p[0x3] = 0;
        p[0x57] = 0;
        *(s16*)(p + 0xB2) = 0x200;
        *(s16*)(p + 0xB6) = 0;
        p[0xAB] = 1;
        p[0xF4] = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
        func_8002385C(0x13, 0xFF, 0);
    }
}
