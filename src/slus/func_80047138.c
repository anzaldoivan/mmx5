#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_800C9310;
extern int func_8002D6FC();

void func_80047138(void* arg0) {
    D_8009A0A0[0xF7] = 0;
    D_800C9310 = 1;
    D_8009A0A0[0x98]--;
    D_8009A0A0[0x99]--;
    func_8002D6FC(arg0);
}
