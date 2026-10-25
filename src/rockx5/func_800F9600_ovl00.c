#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void func_800F9600_ovl00(u8* obj) {
    if (*(s8*)(obj + 0x7) == 1) {
        obj[0x6]++;
    }
    if (!(--*(u16*)(obj + 0x7C) & 1)) {
        *(s32*)(obj + 0x24) = -*(s32*)(obj + 0x24);
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
