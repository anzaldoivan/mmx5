#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F71C0_ovl29(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        func_8002D9EC(obj, 0x30, 0x30);
    } else if (--*(s16*)(obj + 0x8A) == 0) {
        obj[6] -= 2;
    } else {
        obj[5] = 0;
        obj[6] = 0;
        obj[4]++;
    }
}
