#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* obj, s32 a1, s32 a2);
extern void func_80047B10(u8* obj);

void func_80047864(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        func_80047B10(obj);
    } else {
        func_8002D9EC(obj, 0x2C, 0x20);
    }
}
