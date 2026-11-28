#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

void func_800FAA8C_ovl58(UnkObj* arg0) {
    D_8009A1F8.t.pad0[3] = 0;
    D_8009A1F8.t.unk57 = 0;
    *(s16*)&D_8009A1F8.t.padA1[0xB2 - 0xA1] = 0;
    D_8009A1F8.t.padA1[0xAB - 0xA1] = 1;
    D_8009A1F8.t.unkF4 = 1;
    D_8009A1F8.t.unkB6 = 0x100;
    arg0->unk4 = 0;
    play_sound(2, 0x59, 0);
    arg0->unk1++;
}
