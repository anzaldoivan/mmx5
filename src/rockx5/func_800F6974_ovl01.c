#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern s16 D_8009A0AA;

void func_800F6974_ovl01(u8* obj) {
    func_80017248(obj);
    if (D_8009A0AA < *(s16*)(obj + 0xA) + 8 && *(signed char*)(obj + 3) != 0) {
        *(s16*)(obj + 0x7C) = 0x78;
        func_800171E8(obj, 5);
        obj[6]++;
    }
}
