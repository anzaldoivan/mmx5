#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void func_800F8338_ovl03(u8* obj) {
    if (obj[0x70] & 8) {
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
