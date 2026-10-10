#include "types.h"

extern Sel800218E0 D_8009A420;
extern Pad800218E0 D_800C931C;
extern s32 func_80016490(s32, s32, s32);
extern void func_800132F8(s8 arg);

void func_80021318(Arg800218E0* a) {
    s16 lim;
    signed char* p;

    if (D_8009A420.unk4 == 0) {
        p = &D_8009A420.unk7.s;
        lim = a->unk8;
        if (D_800C931C.unk4 & 0x1000) {
            func_80016490(0, 0xC, 0);
            if (D_8009A420.unk7.s == 0) {
                D_8009A420.unk7.s = lim;
            } else {
                D_8009A420.unk7.s--;
            }
        }
        if (D_800C931C.unk4 & 0x4000) {
            func_80016490(0, 0xC, 0);
            if (*p == lim) {
                *p = 0;
            } else {
                (*p)++;
            }
        }
        if (D_800C931C.unk4 & 0x40) {
            func_80016490(0, 0x22, 0);
            func_800132F8(8);
            a->unk1++;
        }
    }
}
