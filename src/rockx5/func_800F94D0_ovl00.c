#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void func_800F94D0_ovl00(u8* obj) {
    if (*(s8*)(obj + 0x46) == 0) {
        *(s16*)(obj + 0x7C) = 0x46;
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
