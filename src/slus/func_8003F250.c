#include "types.h"

extern void func_80016D54(s32, s32);
extern void func_8003CEA4(u8* obj);

void func_8003F250(u8* obj) {
    func_80016D54(1, 7);
    func_8003CEA4(obj);
    obj[0x9B] = 0;
    obj[0x9C] = 0;
    obj[0x9D] = 0;
    obj[0x9E] = 0;
}
