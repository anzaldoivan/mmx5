#include "types.h"

extern void func_8003B33C(u8*, s32);
extern void func_80016490(s32, s32, void*);

void func_8003FBD0(u8* p, s32 arg1) {
    u8* unk; /* the target passes an uninitialised $s1 */
    u16 flags;

    if (arg1 == 0) {
        func_8003B33C(p, 0x62);
    } else {
        func_8003B33C(p, 0x63);
    }
    func_80016490(1, 0x17, unk);
    flags = *(u16*)(p + 0x7C);
    if (flags & 2) {
        p[0x15] = 0;
        *(s32*)(p + 0x20) = -0x20000;
    } else if (flags & 1) {
        p[0x15] = 0x40;
        *(s32*)(p + 0x20) = 0x20000;
    } else {
        *(s32*)(p + 0x20) = 0;
    }
    if (*(s8*)(p + 0x96) == 0x11) {
        *(s32*)(p + 0x20) = 0;
    }
    *(s32*)(p + 0x28) = 0;
    p[0x67] = 1;
    p[5] = 0x29;
    p[6] = 0;
}
