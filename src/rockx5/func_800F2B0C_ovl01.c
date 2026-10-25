#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);

void func_800F2B0C_ovl01(u8* obj) {
    func_80017248(obj);
    func_8002DF54(obj);
    if (--D_1F80004C.bytes[0x80] == 0xFF) {
        obj[5] = 4;
        obj[6] = 0;
    }
}
