#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern s32 func_80032F70(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8003240C(u8* a0);
extern void (*D_800FECAC_ovl39[])(u8* a0);
extern u8 D_8009A0A0[];
extern u8 D_80074EE0[];
extern u8 D_800750C0[];

void func_800FB07C_ovl39(u8* p) {
    s32 r;
    u8 t;
    u8* g;
    u8* h;

    *(u16*)(p + 0x42) &= 0x7FFF;
    D_800FECAC_ovl39[((s8*)p)[5]](p);
    g = D_8009A0A0;
    if (((s8*)g)[2] != 0) {
        r = func_80031DD0(p);
    } else {
        r = func_80032F70(p);
    }
    if (r < 0) {
        p[0x84] = 0x78;
        p[4] = 2;
        return;
    }
    if (r > 0 && r != 0x7F) {
        *(u8**)(p + 0x58) = D_80074EE0;
        p[0x86] = (u32)(r - 0x19) < 2 ? 2 : 0x1E;
    }
    t = p[0x86];
    if (t != 0) {
        p[0x86] = t + 0xFF;
        if (t & 2) {
            *(u16*)(p + 0x42) |= 0x8000;
        } else {
            *(u16*)(p + 0x42) &= 0x7FFF;
        }
        if (p[0x86] == 0) {
            *(u8**)(p + 0x58) = D_800750C0;
            *(u16*)(p + 0x42) &= 0x7FFF;
        }
    }
    func_8002D9EC(p, 0x60, 0x60);
    h = D_8009A0A0;
    if (h[0xF8] == 0) {
        func_8003240C(p);
    }
}
