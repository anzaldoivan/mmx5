#include "types.h"
#include "addr.h"

extern u8 D_800AA9A8[];
extern u8 D_800C9588[];
extern void func_800176B0(void);
extern void func_80013C04(s32);

void func_80013D94(void) {
    u8 i;

    ((u8**)&D_1F800000)[0x40] = D_800AA9A8 + D_1F800000 * 0xA000;
    ((u8**)&D_1F800000)[0x41] = D_800C9588 + D_1F800000 * 0x2000;
    func_800176B0();
    for (i = 0; i < 5; i++) {
        func_80013C04(i);
    }
}
