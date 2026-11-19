#include "types.h"
#include "mmx5/globals.h"

void func_80049EC8(u8* obj) {
    if (++*(s16*)(obj + 0x8C) >= 40) {
        obj[4] = 3;
        obj[3] = 0;
    } else {
        animate_object(obj);
        func_8002D9EC(obj, 0x20, 0x20);
    }
}
