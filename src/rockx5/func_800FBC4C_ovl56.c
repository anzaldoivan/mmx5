#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern u8 D_80091C44;
extern D_8009A1F8_t D_8009A1F8;

void func_800FBC4C_ovl56(UnkObj* arg0) {
    u8* p;

    if (((s8*)arg0)[2] != 0) {
        if (arg0->unk6 == 0) {
            ((u8*)arg0)[2]--;
            func_80016490(0, 0x13, 0);
            arg0->unk6 = 0x3C;
        } else {
            arg0->unk6--;
        }
    }
    if (D_80091C44 == 0) {
        p = (u8*)&D_8009A1F8;
        p[0x3] = 0;
        p[0x57] = 0;
        p[0xAB] = 1;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0x600;
        p[0xF4] = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
