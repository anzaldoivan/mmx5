#include "types.h"

extern void func_8002DF54(u8* a0);

void func_8004A57C(u8* arg0) {
    func_8002DF54(arg0);
    if (++*(s16*)(arg0 + 0x8C) >= 11) {
        *(s16*)(arg0 + 0x8C) = 0;
        arg0[5]++;
    }
}
