#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void func_800FDA0C_ovl04(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (*(s32*)(obj + 0x20) >= -0x10000) {
        *(s32*)(obj + 0x20) = -0x10000;
    }
}
