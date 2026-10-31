#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);
extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 rsin(s32);
extern u8 D_8009A1F8[];
extern u8 D_800FB160_ovl52[];
extern u8 D_800FB360_ovl52[];
extern u8 D_800FB560_ovl52[];
extern u8 D_800FB760_ovl52[];
extern s32 D_800FB964_ovl52;

void func_800FA2DC_ovl52(u8* arg0) {
    s32 s;
    s32 v;
    u8* p;

    s = rsin(D_800FB964_ovl52);
    v = s * 0x10;
    D_800FB964_ovl52 = (D_800FB964_ovl52 + 0x10) & 0xFFF;
    if (v != 0) {
        v = s << 8;
    }
    p = D_8009A1F8;
    *(s32*)(p + 0xB4) = 0x02000000 - v;
    p[0xF4] = 1;
    func_8002C3CC(D_800FB360_ovl52, D_800FB160_ovl52, 0x100,
                  ++*(s16*)(arg0 + 4), 0x78);
    func_8002C338(0x60, D_800FB360_ovl52, 0x10);
    func_8002C3CC(D_800FB760_ovl52, D_800FB560_ovl52, 0x100,
                  0x78 - *(s16*)(arg0 + 4), 0x78);
    func_8002C338(0x70, D_800FB760_ovl52, 0x10);
    if (*(s16*)(arg0 + 4) >= 0x78) {
        func_8002385C(0x49, 0xFF, 0);
        arg0[1]++;
    }
}
