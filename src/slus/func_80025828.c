#include "types.h"

extern void func_80025A74(u8* arg0);
extern void func_80025D94(u8* arg0);
extern void func_80026080(s32 arg0, u8 arg1);
extern void func_800262D8(void* arg0, s32 arg1);
extern u8 D_8009A0A0[];
extern s32 D_8009A420;
extern u8 D_800D1C00[];
extern u8 D_800E92F0;

void func_80025828(void) {
    u8* o;
    u8* g;
    u32 lv;
    s32 snd;
    s32 q;

    o = D_8009A0A0;
    g = D_800D1C00;
    if (*(s8*)(g + 0x1F) != 0) {
        func_800262D8(o, 0);
        if (*(s8*)(o + 2) == 0) {
            func_80025A74(o);
        } else {
            func_80025D94(o);
        }
        if ((s8)D_800D1C00[0xC] != 0 && (s8)D_800D1C00[0xC] != 0x16) {
            if (++D_800E92F0 >= 0x12) {
                D_800E92F0 = 0;
            }
            lv = o[0xFB] & 0x7F;
            if (lv < 10) {
                snd = 0x80;
            } else if (lv < 20) {
                snd = 0x82;
            } else if (lv < 31) {
                snd = 0x84;
            } else {
                snd = 0x86;
            }
            if (D_800E92F0 >= 9) {
                snd = (s16)(snd + 1);
            }
            if (lv == 31) {
                if (D_8009A420 & 4) {
                    func_80026080(10, snd);
                }
            } else {
                func_80026080(10, snd);
            }
        }
        if (*(s8*)(g + 0x24) != 0) {
            snd = D_800D1C00[0xC0];
            q = snd / 10;
            func_80026080(14, q + 0x3B);
            func_80026080(15, snd - q * 10 + 0x3B);
            func_800262D8(*(void**)(g + 0x20), 1);
            if (*(s8*)(g + 0x25) == 0) {
                snd = (*(s8*)(g + 0xA2) - 0x20) / 2 + 0xA3;
                if (snd >= 0xD4) {
                    snd = 0xD3;
                }
                func_80026080(7, snd);
            } else if (*(s8*)(g + 0x25) == 1) {
                snd = (*(s8*)(g + 0xA2) - 0x20) / 2;
                if (snd >= 0x31) {
                    snd = 0x30;
                }
                func_80026080(0x10, snd);
            } else {
                func_80026080(0x11, 0xA2);
            }
        }
    }
}
