#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);

void func_800FBDD4_ovl38(u8* obj) {
    func_80017248(obj);
    D_1F80004C.bytes[0x8D] = 1;
    obj[5] = 3;
    obj[6] = 0;
}
