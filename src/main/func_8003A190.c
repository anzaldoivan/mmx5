#include "types.h"

extern void func_8003C5D8(u8* obj);

void func_8003A190(u8* p) {
    p[0xFB] = 0;
    p[0x14B] = 0;
    p[0x154] = 0;
    if (((s8*)p)[2] != 0) {
        p[0x7A] = 0;
    }
    func_8003C5D8(p);
}
