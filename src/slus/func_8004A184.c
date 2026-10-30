#include "types.h"

extern void func_80017248(u8* obj);

void func_8004A184(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        obj[3] = 0;
        obj[4] = 3;
    }
}
