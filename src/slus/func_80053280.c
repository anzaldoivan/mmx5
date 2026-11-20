#include "types.h"
#include "mmx5/globals.h"

void func_80053280(u8* obj) {
    animate_object(obj);
    *(u16*)(obj + 0x42) &= 0x7FFF;
    if (*(s8*)(obj + 0x45) != 0) {
        func_8002D760(obj);
    }
}
