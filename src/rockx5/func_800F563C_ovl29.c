#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F563C_ovl29(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        obj[6]++;
        func_800171E8(obj, 0);
        if (obj[0x8A] & 1) {
            obj[0x8A] = 0x3D;
        } else {
            obj[0x8A] = 0x3E;
        }
        *(s16*)(obj + 0x7C) = 1;
    }
}
