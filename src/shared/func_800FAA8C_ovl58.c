#include "types.h"
#include "mmx5/sound.h"

extern D_8009A1F8_t D_8009A1F8;

void func_800FAA8C_ovl58(UnkObj* arg0) {
    D_8009A1F8.pad0[3] = 0;
    D_8009A1F8.unk57 = 0;
    *(s16*)&D_8009A1F8.padA1[0xB2 - 0xA1] = 0;
    D_8009A1F8.padA1[0xAB - 0xA1] = 1;
    D_8009A1F8.unkF4 = 1;
    D_8009A1F8.unkB6 = 0x100;
    arg0->unk4 = 0;
    play_sound(2, 0x59, 0);
    arg0->unk1++;
}
