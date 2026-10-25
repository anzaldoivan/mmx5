#include "types.h"

extern void func_8002DF54(u8* a0);

void func_8004849C(u8* a0) {
    func_8002DF54(a0);
    if (((s8*)a0)[0x98] != 0 || --a0[0x8D] == 0) {
        a0[4] = 2;
    }
}
