#include "types.h"
#include "mmx5/globals.h"

extern void func_8003AA4C(u8* obj);

void func_80040598(u8* p) {
    animate_object(p);
    if (*(s8*)(p + 0x46) == 0 || *(s8*)(p + 0x93) != 1) {
        func_8003AA4C(p);
    }
}
