#include "types.h"
#include "mmx5/globals.h"

extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_8010000C_ovl04(u8* p) {
    func_8002C218();
    D_800D50DE = 0;
    D_8009A42E = 0;
    D_80093E68 = 0;
    p[0x1A] = 0;
    p[0x18] = 0x28;
    p[0x19] = 4;
    p[4]++;
}
