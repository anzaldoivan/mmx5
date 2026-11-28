#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"

extern void func_80046030(void* arg0);

void func_80045F30(u8* p) {
    *(s32*)(p + 0x50) = 0;
    *(s32*)(p + 0x68) = 0;
    if (*(s8*)(p + 0x98) > 0) {
        func_80046030(p);
        return;
    }
    *(s32*)(p + 0x20) = -*(s32*)(p + 0x20);
    if (random_byte() & 1) {
        *(s32*)(p + 0x24) = 0x40CCB;
    } else {
        *(s32*)(p + 0x24) = -0x40CCB;
    }
    p[4] = 2;
    p[5] = 0;
    p[0x15] ^= 0x40;
    func_8002D9EC(p, 12, 8);
}
