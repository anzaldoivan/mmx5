#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F4DD0_ovl26(u8* a0) {
    u8* s;

    func_80017248(a0);
    s = D_1F80004C.bytes;
    if (s[0x97] == 1) {
        s[0x97] = 0;
        func_800171E8(a0, 6);
        a0[6]++;
    }
}
