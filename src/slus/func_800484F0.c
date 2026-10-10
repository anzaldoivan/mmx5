#include "types.h"

extern u8 D_8009A0A0[];
extern int func_8002D6FC();

void func_800484F0(u8* e) {
    if ((e[2] & 0x3F) == 0) {
        D_8009A0A0[0x98]--;
        D_8009A0A0[0x99]--;
    }
    func_8002D6FC(e);
}
