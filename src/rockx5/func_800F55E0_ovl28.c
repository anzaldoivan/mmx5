#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_80044DE0();
extern void func_800171E8(u8* obj, s32 state);

void func_800F55E0_ovl28(u8* obj) {
    func_80017248(obj);
    if (func_80044DE0() == 0) {
        obj[7] = 2;
        if (*(s16*)(obj + 0x7E) != 0) {
            *(s16*)(obj + 0x7E) -= 1;
        } else {
            func_800171E8(obj, 0xC);
            obj[6]++;
        }
    }
}
