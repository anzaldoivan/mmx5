#include "types.h"
#include "mmx5/globals.h"

void func_800F71C0_ovl29(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        func_8002D9EC(obj, 0x30, 0x30);
    } else if (--*(s16*)(obj + 0x8A) == 0) {
        obj[6] -= 2;
    } else {
        obj[5] = 0;
        obj[6] = 0;
        obj[4]++;
    }
}
