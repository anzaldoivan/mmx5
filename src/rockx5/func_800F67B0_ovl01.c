#include "types.h"
#include "addr.h"

extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* a0);
extern void func_800F6C48_ovl01(u8* a0);

void func_800F67B0_ovl01(u8* a0) {
    func_8002DF54(a0);
    func_80017248(a0);
    if (--D_1F80004C.bytes[0x85] == 0xFF) {
        if (--D_1F80004C.bytes[0x84] == 0xFF) {
            a0[5] = 3;
            func_800F6C48_ovl01(a0);
        }
        a0[6] = 0;
    }
}
