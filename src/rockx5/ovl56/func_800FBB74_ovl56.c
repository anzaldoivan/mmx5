#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern u8 D_8009A1F8[];

void func_800FBB74_ovl56(UnkObj* arg0) {
    u8* p;
    u8 n;

    n = arg0->pad2[0];
    if (*(s8*)&arg0->pad2[0] != 0) {
        if (arg0->unk6 == 0) {
            arg0->pad2[0] = n - 1;
            play_sound(0, 0x13, 0);
            arg0->unk6 = 0x3C;
        } else {
            arg0->unk6--;
        }
    }
    p = D_8009A1F8;
    p[0x4C] = 1;
    *(s32*)(p + 8) += 0xFFFBBBBC;
    arg0->unk4++;
    if (arg0->unk4 >= 30) {
        *(s16*)(p + 0xA) = 0x180;
        p[0x4C] = 1;
        func_8002385C(0x6B, 0xFF, 0);
        arg0->unk1++;
    }
}
