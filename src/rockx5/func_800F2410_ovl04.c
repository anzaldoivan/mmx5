#include "types.h"

extern int func_8002D7A0();
extern u8 D_8009A0A0[];

void func_800F2410_ovl04(u8* arg0) {
    u8* p;

    if (((s8*)arg0)[5] == 4) {
        p = D_8009A0A0;
        p[0xCA] = 0;
        if (p[0x5C] & 0x7F) {
            p[3] = 1;
        }
    }
    func_8002D7A0();
}
