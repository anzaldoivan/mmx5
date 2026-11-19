#include "types.h"
#include "mmx5/globals.h"

extern void func_8003AA4C(u8* obj);

void func_80040500(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0 || *(s8*)(obj + 0x93) != 5) {
        func_8003AA4C(obj);
    }
}
