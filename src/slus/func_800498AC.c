#include "types.h"

extern u8 D_8009A0A0[];
extern int func_8002D6FC();

void func_800498AC(u8* obj) {
    u8* p = D_8009A0A0;

    p[0x98]--;
    p[0x99]--;
    p[0xA6]--;
    func_8002D6FC(obj);
}
