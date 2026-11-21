#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"

extern u8 D_8009A240;

void func_800F5154_ovl04(u8* obj) {
    animate_object(obj);
    obj[0x91] = random_byte() & 0xF;
    if (obj[0x91] < 5) {
        obj[0x91] = 0;
    } else if (obj[0x91] < 8) {
        obj[0x91] = 1;
    } else if (obj[0x91] < 11) {
        obj[0x91] = 2;
    } else {
        obj[0x91] = 3;
    }
    func_8003D2C4();
    ((s8*)obj)[0x90] = -1;
    obj[0x8D] = 0;
    obj[5] = 4;
    obj[6] = 0;
    obj[4]++;
    D_8009A240 = 2;
}
