#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);

void func_800F2B50_ovl11(u8* obj) {
    s32 v;

    func_80017248(obj);
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
