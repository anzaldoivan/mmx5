#include "types.h"

extern void func_80033024(u8* a0);
extern s32 func_800326BC(u8* a0);
extern s32 func_8003240C(u8* a0);
extern void func_8003258C(u8* a0);
extern void (*D_8010108C_ovl07[])(u8* a0);
extern u8 D_8009A0A0[];

void func_800F2CF8_ovl07(u8* a0) {
    u8* g;
    s16 gx;
    s16 x;

    D_8010108C_ovl07[((s8*)a0)[6]](a0);
    func_80033024(a0);
    func_800326BC(a0);
    g = D_8009A0A0;
    if (g[0xF8] == 0) {
        gx = *(s16*)(g + 0xA);
        x = *(s16*)(a0 + 0xA);
        if ((gx - x) >= 0 ? (gx - x) < 0x41 : (x - gx) < 0x41) {
            func_8003240C(a0);
        }
    }
    func_8003258C(a0);
}
