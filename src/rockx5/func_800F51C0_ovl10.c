#include "types.h"

extern void func_8002DED4(u8* obj);

void func_800F51C0_ovl10(u8* obj) {
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        obj[0x61] = 0;
        obj[0x6] = 3;
    }
}
