#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F2D48_ovl11(u8* obj) {
    u8 flags;

    func_80017248(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        flags = D_1F80004C.bytes[0x82];
        if (flags & 0x80) {
            switch (flags & 3) {
            case 0:
                func_800171E8(obj, 0xD);
                break;
            case 1:
                func_800171E8(obj, 0xC);
                break;
            case 2:
                func_800171E8(obj, 0xE);
                break;
            }
        } else {
            func_800171E8(obj, 0x1A);
        }
        obj[6]++;
    }
}
