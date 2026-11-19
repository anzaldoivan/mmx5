#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800D1C00[];

void func_800FC468_ovl39(u8* obj) {
    u8* p = D_800D1C00;
    func_8002385C(0x49, 0xFF, p[0x2F]);
    p[0x2F] = 1;
    obj[6]++;
}
