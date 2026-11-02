#include "types.h"

extern void SetDrawOffset(u8*, s16*);
extern void SetDrawArea(u8*, s16*);
extern s16 D_8006FAE0[];
extern u8 D_800D1C00[];
extern u8 D_800D5188[];
extern u8 D_800D51C8[];

void func_80011FD4(s8 arg0, s8 arg1) {
    s16 rect[4];
    s16 ofs[4];
    s32 v;
    s32 v2;

    D_8006FAE0[0] = arg0;
    D_8006FAE0[1] = arg1;
    ofs[0] = (s8)D_800D1C00[0x1B8];
    ofs[2] = (s8)D_800D1C00[0x1B8];
    ofs[1] = (s8)D_800D1C00[0x1B9];
    ofs[3] = (s8)D_800D1C00[0x1B9] + 0xF0;
    SetDrawOffset(D_800D5188, &ofs[0]);
    SetDrawOffset(D_800D5188 + 0xC, &ofs[2]);
    v = (s8)D_800D1C00[0x1B8];
    if (v < 0) {
        rect[0] = 0;
        rect[2] = v + 0x140;
    } else {
        rect[0] = v;
        rect[2] = 0x140 - v;
    }
    v2 = (s8)D_800D1C00[0x1B9];
    if (v2 < 0) {
        rect[1] = 0;
        rect[3] = v2 + 0xF0;
    } else {
        rect[1] = v2;
        rect[3] = 0xF0 - v2;
    }
    SetDrawArea(D_800D51C8, rect);
    rect[1] += 0xF0;
    SetDrawArea(D_800D51C8 + 0xC, rect);
}
