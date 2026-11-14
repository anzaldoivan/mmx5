#include "types.h"

extern void func_8002C338(s32, void*, s32);
extern u8 D_800FC6B8_ovl55[];
extern u8 D_800FBEB8_ovl55[];
extern u8 D_800FC2B8_ovl55[];
extern u8* D_800FD2B8_ovl55;
extern D_8009A1F8_t D_8009A1F8;

void func_800FAD38_ovl55(u8* a0) {
    D_8009A1F8_t* p = &D_8009A1F8;

    ((u8*)p)[3] = 0;
    func_8002C338(0x40, D_800FC6B8_ovl55, 0x10);
    func_8002C338(0x100, D_800FBEB8_ovl55, 0x10);
    func_8002C338(0x50, D_800FC2B8_ovl55, 0x10);
    p->unk62 = 0x100;
    p->unkA0 = 1;
    p->unk5E = 0;
    D_800FD2B8_ovl55[4] = 2;
    a0[1]++;
}
