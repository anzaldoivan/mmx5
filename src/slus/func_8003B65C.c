#include "types.h"

extern void func_8003D548();
extern void func_8003B82C(u8* arg0);
extern s8 D_800D1C00[];

void func_8003B65C(u8* arg0) {
    s8* p;

    func_8003D548();
    if (*(s32*)(arg0 + 0xFC) & 8) {
        *(s32*)(arg0 + 0x144) -= 0x1080;
    }
    if (arg0[0xFA] == 3) {
        *(s32*)(arg0 + 0x120) = 0;
        *(s32*)(arg0 + 0x114) += 0xFFFE6000;
        *(s32*)(arg0 + 0x118) += 0xFFFEF800;
        *(s32*)(arg0 + 0x11C) -= 0xC00;
        *(s32*)(arg0 + 0x13C) += 0xFFFEF800;
        *(s32*)(arg0 + 0x140) += 0xFFFEF800;
    }
    if (*(s32*)(arg0 + 0xFC) & 0x10) {
        *(s32*)(arg0 + 0x114) += 0x1A000;
        *(s32*)(arg0 + 0x118) += 0x10800;
        *(s32*)(arg0 + 0x11C) += 0xC00;
        *(s32*)(arg0 + 0x13C) += 0x10800;
        *(s32*)(arg0 + 0x140) += 0x10800;
    }
    if (*(s32*)(arg0 + 0xFC) & 4) {
        *(s32*)(arg0 + 0x100) += 0x4000;
        *(s32*)(arg0 + 0x104) += 0x10000;
    }
    if (arg0[0xFA] == 3) {
        *(s32*)(arg0 + 0x128) += 0x8000;
        *(s32*)(arg0 + 0x12C) += 0xC000;
    }
    p = D_800D1C00;
    if (p[0xC] == 3) {
        switch (p[0x1D]) {
        case 0 ... 3:
        case 5 ... 6:
            func_8003B82C(arg0);
            break;
        }
    } else if (p[0xC] == 12) {
        if (p[0x1D] == 4) {
            func_8003B82C(arg0);
        }
    }
}
