#include "types.h"
#include "mmx5/globals.h"

extern void func_80047B10(u8* obj);

void func_80047864(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        func_80047B10(obj);
    } else {
        func_8002D9EC(obj, 0x2C, 0x20);
    }
}
