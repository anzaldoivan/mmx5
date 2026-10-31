#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern u8 D_80101CE4_ovl04[];
extern u8 D_80101CEC_ovl04[];

void func_800F6B0C_ovl04(u8* obj) {
    u8 flags;
    s32 vx;

    flags = obj[0x93];
    if (!(flags & 8)) {
        *(u8**)(obj + 0x50) = D_80101CE4_ovl04;
        *(u8**)(obj + 0x68) = D_80101CEC_ovl04;
        obj[5] = 4;
        obj[6] = 0;
        if (*(s32*)(obj + 0x20) > 0) {
            obj[0x15] = 0;
        } else {
            obj[0x15] = 0x40;
        }
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0xFFFE0000;
        *(u16*)(obj + 0xE) += 3;
        func_800171E8(obj, 0xD);
        *(u8**)(obj + 0x68) = D_80101CEC_ovl04;
        obj[0x67] = 0;
    } else {
        vx = *(s32*)(obj + 0x20);
        if ((vx < 0 && (flags & 2)) || (vx > 0 && (flags & 1))) {
            obj[0x8F] = 8;
            func_800171E8(obj, 0xE);
            obj[4] = 2;
        }
    }
    func_80017248(obj);
    func_8002DF54(obj);
}
