#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_8004A83C(u8* o) {
    func_80017248(o);
    if (*(s8*)(o + 0x46) == 0) {
        o[3] = 0;
        o[4] = 3;
    }
    func_8002D9EC(o, 0x20, 0x20);
}
