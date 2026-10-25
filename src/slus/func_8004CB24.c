#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D078();
extern signed char D_8009A0A5;

void func_8004CB24(u8* p) {
    u8* q;

    func_80017248(p);
    if (*(s8*)(p + 0x45) & 0x80) {
        p[0x45] &= 0x7F;
        q = func_8002D078();
        if (q != 0) {
            q[0] = 1;
            q[1] = 0x2C;
            q[2] = 0;
            q[0x14] = p[0x14];
            *(s32*)(q + 0x84) = p[0x17];
            *(u8**)(q + 0x7C) = p;
        }
    }
    if (D_8009A0A5 != 0x3B) {
        p[4]++;
    } else if (*(s8*)(p + 0x46) == 0) {
        p[5] = 1;
        *(s16*)(p + 0x88) = 0;
    }
}
