#include "types.h"

extern s32 func_8002C338(s32, void*, s32);
extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002DF78(void);
extern u8 D_8009A1F8[];
extern u8 D_800FBAB8_ovl55[];
extern u8 D_800FBCB8_ovl55[];
extern u8 D_800FBEB8_ovl55[];
extern u8 D_800FC0B8_ovl55[];
extern u8 D_800FC2B8_ovl55[];
extern u8 D_800FC4B8_ovl55[];
extern u8 D_800FC6B8_ovl55[];
extern u8 D_800FC8B8_ovl55[];

void func_800FA478_ovl55(u8* arg0) {
    u8* r;
    s32 t;

    t = *(u16*)(arg0 + 4) + 1;
    *(u16*)(arg0 + 4) = t;
    if (t & 1) {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0xA) = func_8002DF78() % 9;
        *(s16*)(p + 0xE) = func_8002DF78() % 5;
    } else {
        u8* q = D_8009A1F8;
        *(s16*)(q + 0xA) = 0;
        *(s16*)(q + 0xE) = 0;
    }
    r = D_8009A1F8;
    r[0x4C] = 1;
    func_8002C3CC(D_800FC0B8_ovl55, D_800FBEB8_ovl55, 0x100, *(s16*)(arg0 + 4),
                  0x1E);
    func_8002C338(0x100, D_800FC0B8_ovl55, 0x10);
    func_8002C3CC(D_800FC4B8_ovl55, D_800FC2B8_ovl55, 0x100, *(s16*)(arg0 + 4),
                  0x1E);
    func_8002C338(0x50, D_800FC4B8_ovl55, 0x10);
    func_8002C3CC(D_800FC8B8_ovl55, D_800FC6B8_ovl55, 0x100, *(s16*)(arg0 + 4),
                  0x1E);
    func_8002C338(0x40, D_800FC8B8_ovl55, 0x10);
    func_8002C3CC(D_800FBCB8_ovl55, D_800FBAB8_ovl55, 0x100,
                  0x1E - *(s16*)(arg0 + 4), 0x1E);
    func_8002C338(0x60, D_800FBCB8_ovl55, 0x10);
    r[3] = 1;
    if (*(s16*)(arg0 + 4) >= 0x1E) {
        *(u16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
