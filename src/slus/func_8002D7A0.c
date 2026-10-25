#include "types.h"

extern int func_8002D6FC();

void func_8002D7A0(u8* arg0) {
    u8* p;
    u8* q;

    p = *(u8**)(arg0 + 0x10);
    if (p != 0) {
        *p &= 0x70;
        q = *(u8**)(arg0 + 0x10);
        if ((q[3] & 0xF0) == 0x10) {
            q[3] &= 0xF;
        }
    }
    func_8002D6FC(arg0);
}
