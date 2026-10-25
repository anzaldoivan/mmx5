#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);

void func_800F2948_ovl11(u8* obj) {
    s32 st;

    func_80017248(obj);
    func_8002DF54(obj);
    st = obj[0x15];
    if (st != 0) {
        if (obj[0x70] & 1) {
            obj[0x15] = 0;
            *(s32*)(obj + 0x20) = -*(s32*)(obj + 0x20);
        }
    } else if (obj[0x70] & 2) {
        st = 0x40;
        obj[0x15] = st;
        *(s32*)(obj + 0x20) = -*(s32*)(obj + 0x20);
    }
}
