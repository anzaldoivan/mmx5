#include "types.h"

extern s32 SsVabTransCompleted(s32);
extern s32 SsVabTransBodyPartly(s32, s32, s32);
extern u32 D_800E5A38;
extern u8 D_800D5208[];
extern s8 D_80093E60[];
extern Rec5A58 D_800E5A58[];
extern u8 D_800E5208;

void func_800153FC(void) {
    u32 n;
    s8* p;
    s32 r;
    u32 i;
    u8 c;
    u8* d;
    u32 o;
    s8* e;

    if (D_800E5A58[D_800E5208].unk8 != 0xFFFF) {
        while (SsVabTransCompleted(0) == 0) {
        }
    } else {
        D_800E5A58[D_800E5208].unk8 = 0;
    }
    i = D_800E5208;
    n = D_800E5A38;
    c = D_800E5A58[i].unk4;
    if (n > 0x800) {
        n = 0x800;
    }
    o = i << 11;
    d = D_800D5208;
    e = D_80093E60;
    p = &e[c];
    r = SsVabTransBodyPartly((s32)&d[o], n, *p);
    D_800E5A38 -= n;
    if (D_800E5A38 == 0 && r == *p) {
        while (SsVabTransCompleted(0) == 0) {
        }
    }
}
