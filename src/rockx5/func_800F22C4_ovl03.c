#include "types.h"

extern void func_80032F70(u8* a0);
extern void func_80033024(u8* a0);
extern s32 func_800326BC(u8* a0);
extern s32 func_8002D800(u8* a0);
extern void func_8002D89C(u8* a0);
extern int func_8002D760();
extern s32 func_8003240C(u8* a0);
extern void func_8003258C(u8* a0);
extern s32 func_8002FB58(u8* obj);
extern void (*D_800F9D00_ovl03[])(u8* a0);
extern u8 D_8009A0A0[];

void func_800F22C4_ovl03(u8* a0) {
    u8* g;
    s16 gx;
    s16 x;

    func_80032F70(a0);
    func_80033024(a0);
    func_800326BC(a0);
    D_800F9D00_ovl03[((s8*)a0)[6]](a0);
    if (func_8002D800(a0) == 0) {
        func_8002D89C(a0);
    } else {
        func_8002D760(a0);
    }
    g = D_8009A0A0;
    if (g[0xF8] == 0) {
        gx = *(s16*)(g + 0xA);
        x = *(s16*)(a0 + 0xA);
        if ((gx - x) >= 0 ? (gx - x) < 0x31 : (x - gx) < 0x31) {
            func_8003240C(a0);
        }
    }
    func_8003258C(a0);
    if (a0[0x70] & 8) {
        a0[0x67] = 0;
    } else {
        s32 v = *(s32*)(a0 + 0x24);
        if (v < 0) {
            v = -1;
        } else {
            v = 1;
        }
        a0[0x67] = v;
    }
    func_8002FB58(a0);
}
