#include "types.h"

void func_8002DF54(u8* a0);

void func_800F8DB8_ovl09(u8* o) {
    func_8002DF54(o);
    if (*(s16*)(o + 0xE) < 0x821) {
        o[4] = 4;
        o[5] = 0;
        o[6] = 0;
    }
}
