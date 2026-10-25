#include "types.h"

extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);

void func_800FAEB4_ovl28(u8* obj) {
    if (++*(s32*)(obj + 0x8C) == 0x12) {
        obj[4] = 2;
    }
    func_8002D9EC(obj, 0x20, 0x20);
    func_80017248(obj);
    func_8002DF54(obj);
}
