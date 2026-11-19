#include "types.h"
#include "mmx5/globals.h"

void func_8004A83C(u8* o) {
    animate_object(o);
    if (*(s8*)(o + 0x46) == 0) {
        o[3] = 0;
        o[4] = 3;
    }
    func_8002D9EC(o, 0x20, 0x20);
}
