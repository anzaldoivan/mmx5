#include "types.h"

extern void func_8002DED4(u8* obj);

void func_800F5E14_ovl26(u8* obj) {
    if (*(s16*)(obj + 0x90) != 0) {
        (*(s16*)(obj + 0x90))--;
        return;
    }
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        obj[6]++;
    }
}
