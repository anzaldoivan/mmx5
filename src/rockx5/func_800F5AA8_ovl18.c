#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F5AA8_ovl18(u8* o) {
    func_80017248(o);
    if (--o[0x7C] == 0) {
        func_800171E8(o, 2);
        *(s32*)(o + 0x68) = 0;
        *(s32*)(o + 0x54) = 0;
        o[6]++;
    }
}
