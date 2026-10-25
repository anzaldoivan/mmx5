#include "types.h"

extern void func_80028B18(s32, s32, s32, void*);
extern u8 D_8010177C_ovl04[];
extern u8 D_8009A244;

void func_800F3C2C_ovl04(u8* obj) {
    func_80028B18(0, 0x1240, 0x400, D_8010177C_ovl04);
    D_8009A244 = 1;
    obj[4] = 2;
}
