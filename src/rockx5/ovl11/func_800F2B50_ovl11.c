#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

void func_800F2B50_ovl11(u8* obj) {
    s32 v;

    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        v = 2;
        if (D_1F80004C.bytes[0x85] == 2) {
            v = 7;
        }
        obj[5] = v;
        obj[6] = 0;
        obj[0x67] = 0;
    }
}
