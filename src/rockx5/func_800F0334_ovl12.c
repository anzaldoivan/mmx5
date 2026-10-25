#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void func_800F0334_ovl12(u8* o) {
    if (*(s8*)(o + 0x45) == 2) {
        *(s16*)(o + 0x7C) = 0;
        *(s16*)(o + 0x7E) = 0;
        o[6]++;
    }
    func_80017248(o);
    func_8002DED4(o);
}
