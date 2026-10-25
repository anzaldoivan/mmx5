#include "types.h"

extern void func_8002DF54(u8* a0);

void func_800F7570_ovl26(u8* a0) {
    func_8002DF54(a0);
    if (--*(s16*)(a0 + 0x88) == 0) {
        a0[6]++;
    }
}
