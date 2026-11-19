#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#define D_8009A420_as_Sel800218E0 (*(Sel800218E0*)&D_8009A420)
#define D_800C931C_as_Pad800218E0 (*(Pad800218E0*)&D_800C931C)

extern void func_800132F8(s8 arg);

void func_800218E0(Arg800218E0* a) {
    s16 lim;
    signed char* p;

    if (D_8009A420_as_Sel800218E0.unk4 == 0) {
        p = &D_8009A420_as_Sel800218E0.unk7.s;
        lim = a->unk8;
        if (D_800C931C_as_Pad800218E0.unk4 & 0x1000) {
            play_sound(0, 0xC, 0);
            if (D_8009A420_as_Sel800218E0.unk7.s == 0) {
                D_8009A420_as_Sel800218E0.unk7.s = lim;
            } else {
                D_8009A420_as_Sel800218E0.unk7.s--;
            }
        }
        if (D_800C931C_as_Pad800218E0.unk4 & 0x4000) {
            play_sound(0, 0xC, 0);
            if (*p == lim) {
                *p = 0;
            } else {
                (*p)++;
            }
        }
        if (D_800C931C_as_Pad800218E0.unk4 & 0x40) {
            play_sound(0, 0x22, 0);
            if (D_8009A420_as_Sel800218E0.unk7.u != 0) {
                func_800132F8(8);
            }
            a->unk1++;
        }
    }
}
