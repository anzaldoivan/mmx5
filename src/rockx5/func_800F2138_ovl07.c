#include "types.h"

extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s8 D_800D1C1D;
extern void* D_80101044_ovl07[];

void func_800F2138_ovl07(u8* o) {
    s8 st;

    st = ((s8*)o)[5];
    if (st == 5) {
        func_80031DD0(o);
        func_800317B8(o);
    } else {
        if (st != 4 || ((s8*)o)[6] >= 3) {
            if (((s8*)o)[2] != 0) {
                ((s8*)o)[0x8C] = -4;
                o[0x8E] = 8;
                o[0x8D] = ((*(s16*)(o + 0x7E) - *(s16*)(o + 0xE)) >= 0
                               ? (o[0x7E] - o[0xE])
                               : (o[0xE] - o[0x7E])) -
                          0x43;
                o[0x8F] = 0x4A - ((*(s16*)(o + 0x7E) - *(s16*)(o + 0xE)) >= 0
                                      ? (o[0x7E] - o[0xE])
                                      : (o[0xE] - o[0x7E]));
            } else {
                ((s8*)o)[0x8D] = -4;
                o[0x8F] = 8;
                o[0x8C] = ((*(s16*)(o + 0x7C) - *(s16*)(o + 0xA)) >= 0
                               ? (o[0x7C] - o[0xA])
                               : (o[0xA] - o[0x7C])) -
                          0x54;
                o[0x8E] = 0x58 - ((*(s16*)(o + 0x7C) - *(s16*)(o + 0xA)) >= 0
                                      ? (o[0x7C] - o[0xA])
                                      : (o[0xA] - o[0x7C]));
            }
            func_800317B8(o);
        }
        o[0x85] = 0;
        o[0x85] = func_80031DD0(o);
        if (*(s16*)(o + 0xA) == 0x19B8 && D_800D1C1D == 2) {
            *(s16*)(o + 0x88) = 0;
        }
    }
    ((void (*)(u8*))D_80101044_ovl07[((s8*)o)[5]])(o);
    func_8002D9EC(o, 0x80, 0x80);
}
