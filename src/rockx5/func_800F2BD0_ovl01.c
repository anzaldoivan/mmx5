#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern void func_800171E8(u8* obj, s32 state);

void func_800F2BD0_ovl01(u8* obj) {
    s32 vx;

    func_80017248(obj);
    func_8002DF54(obj);
    if (--D_1F80004C.bytes[0x80] == 0xFF) {
        func_800171E8(obj, 3);
        obj[5] = 6;
        obj[6] = 0;
        vx = -0x20000;
        if (obj[0x15] != 0) {
            vx = 0x20000;
        }
        *(s32*)(obj + 0x20) = vx;
        *(s32*)(obj + 0x24) = 0x25000;
        *(s32*)(obj + 0x2C) = 0x1800;
        *(s32*)(obj + 0x28) = 0;
        obj[0x67] = 1;
    }
}
