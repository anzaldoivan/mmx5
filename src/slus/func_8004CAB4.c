#include "types.h"

extern void func_80017248(u8* obj);

void func_8004CAB4(u8* obj) {
    s32 t;

    func_80017248(obj);
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
