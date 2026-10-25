#include "types.h"

extern Pad800218E0 D_800C931C;
extern s32 func_80016490(s32, s32, s32);

void func_800211C4(signed char* p, s32 lim) {
    if (D_800C931C.unk4 & 0x1000) {
        func_80016490(0, 0xC, 0);
        if (*p == 0) {
            *p = lim;
        } else {
            (*p)--;
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
}
