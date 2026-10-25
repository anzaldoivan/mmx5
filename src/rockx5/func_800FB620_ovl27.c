#include "types.h"

extern void func_8002DF54(u8* a0);

void func_800FB620_ovl27(u8* obj) {
    func_8002DF54(obj);
    if (--*(s16*)(obj + 0x88) == 0) {
        obj[4] += 1;
    }
}
