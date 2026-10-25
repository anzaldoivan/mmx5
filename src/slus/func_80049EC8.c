#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_80049EC8(u8* obj) {
    if (++*(s16*)(obj + 0x8C) >= 40) {
        obj[4] = 3;
        obj[3] = 0;
    } else {
        func_80017248(obj);
        func_8002D9EC(obj, 0x20, 0x20);
    }
}
