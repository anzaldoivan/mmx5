#include "types.h"
#include "mmx5/globals.h"

void func_8004CAB4(u8* obj) {
    s32 t;

    animate_object(obj);
    t = *(u16*)(obj + 0x88) + 1;
    *(u16*)(obj + 0x88) = t;
    if ((s16)t >= 16) {
        obj[4]++;
    } else if (t & 1) {
        obj[3] = 0;
    } else {
        obj[3] = 1;
    }
}
