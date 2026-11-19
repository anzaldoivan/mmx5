#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void func_800177B0(s32, s32);
extern u8 D_8009A1F8[];

void func_800FA410_ovl45(Ovl45State* arg0) {
    u8* p;

    if (arg0->unk4 == 0) {
        func_800177B0(0x1A, 0x7F);
        play_sound(2, 0x4D, 0);
        func_8002385C(0x17, 0xFF, 0);
        p = D_8009A1F8;
        *(s16*)(p + 0x5E) = 0;
        *(s16*)(p + 0x62) = 0;
        p[0x57] = 1;
        p[0xA0] = 1;
        arg0->unk1++;
    }
}
