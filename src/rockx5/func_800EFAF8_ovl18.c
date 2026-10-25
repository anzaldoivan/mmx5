#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800EFAF8_ovl18(u8* o) {
    func_80017248(o);
    if (*(s8*)(o + 0x46) == 0) {
        o[0x16] = 1;
        func_800171E8(o, 3);
        o[5]++;
    }
}
