#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800750C0[];
extern u8 D_800F9964_ovl11[];
extern u8 D_800F9968_ovl11[];

void func_800F289C_ovl11(u8* obj) {
    s32 vel;

    *(u8**)(obj + 0x58) = D_800750C0;
    *(u8**)(obj + 0x54) = D_800F9964_ovl11;
    *(u8**)(obj + 0x50) = D_800F9968_ovl11;
    obj[6]++;
    if (D_1F80004C.bytes[0x86] == 0) {
        vel = -0x1C000;
        if (obj[0x15] != 0) {
            vel = 0x1C000;
        }
        *(s32*)(obj + 0x20) = vel;
    } else {
        vel = -0x30000;
        if (obj[0x15] != 0) {
            vel = 0x30000;
        }
        *(s32*)(obj + 0x20) = vel;
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    func_800171E8(obj, 1);
}
