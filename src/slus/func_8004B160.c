#include "types.h"
#include "mmx5/globals.h"

void func_8004B160(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        obj[3] = 0;
        obj[4] = 3;
    }
    func_8002D9EC(obj, 0x40, 0xA0);
}
