#include "types.h"

extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F42C0_ovl26(u8* obj) {
    func_8002DF54(obj);
    func_80017248(obj);
    if (*(s16*)(obj + 0xE) < 0x123D) {
        *(s32*)(obj + 0x24) = 0;
        obj[6]++;
        func_800171E8(obj, 0xF);
    }
}
