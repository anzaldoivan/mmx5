#include "types.h"

extern void func_8003C5D8(u8* obj);

void func_8003CE64(u8* obj) {
    obj[0x84] = 0;
    obj[0x86] = 0;
    obj[0x8C] = 0;
    obj[0x8E] = 0;
    obj[0x8F] = 0;
    obj[0x90] = 0;
    obj[0x91] = 0;
    obj[0x92] = 0;
    obj[0xA2] = 0;
    func_8003C5D8(obj);
}
