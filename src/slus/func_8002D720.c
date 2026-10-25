#include "types.h"

extern int func_8002D6FC();

void func_8002D720(u8* arg0) {
    u8* p;

    p = *(u8**)(arg0 + 0x10);
    if (p != 0) {
        *p |= 0x80;
    }
    func_8002D6FC(arg0);
}
