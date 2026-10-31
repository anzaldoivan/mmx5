#include "types.h"

extern void func_8002DED4(u8* obj);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F59EC_ovl10(u8* obj) {
    func_8002DED4(obj);
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 2 && *(s32*)(obj + 0x24) <= 0) {
        func_800171E8(obj, 3);
    }
    if ((obj[0x70] & 8) && *(s32*)(obj + 0x24) <= 0) {
        if (*(s16*)(obj + 0x7C) != 0) {
            obj[6] = 1;
            *(u16*)(obj + 0x7C) = *(u16*)(obj + 0x7C) - 1;
            if (obj[0x8A] != 0 && *(s8*)(obj + 2) == 0 &&
                *(s32*)(obj + 0x94) == 0) {
                func_800171E8(obj, 0);
                obj[0x8F] = 0x14;
                *(s16*)(obj + 0x7E) = 0x14;
            }
        } else {
            obj[6] = 3;
            func_800171E8(obj, 0);
            *(s16*)(obj + 0x7C) = 0x3C;
        }
    }
}
