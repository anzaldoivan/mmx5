#include "types.h"

extern s32 func_80024548(s32);
extern u8 D_80091C44;
extern u8 D_800D1C00[];

void func_800FC678_ovl39(u8* obj) {
    u8* p;
    if (D_80091C44 == 0) {
        p = D_800D1C00;
        p[0x24] = 1;
        p[0x25] = 1;
        *(u8**)(p + 0x20) = obj;
        p[0xA2] = 0x60;
        func_80024548(-1);
        obj[6]++;
    }
}
