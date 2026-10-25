#include "types.h"

extern u8 D_8009A0A0[];
extern void func_8002D6FC(u8* obj);

void func_8004CC34(u8* obj) {
    if ((s8)D_8009A0A0[5] == 0x3B) {
        D_8009A0A0[6] = 2;
    }
    func_8002D6FC(obj);
}
