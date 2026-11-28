#include "types.h"

extern void func_8003C5D8(u8* obj);

void func_8003A1C8(u8* p) {
    if (*(s8*)(p + 0x14B) > 0) {
        p[0x14B] = 0;
        p[0x154] = 0;
        func_8003C5D8(p);
    }
}
