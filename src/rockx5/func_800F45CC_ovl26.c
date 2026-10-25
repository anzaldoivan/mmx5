#include "types.h"

extern void func_8002DED4(u8* obj);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern s8 D_800FA683_ovl26;

void func_800F45CC_ovl26(u8* obj) {
    func_8002DED4(obj);
    func_80017248(obj);
    if (D_800FA683_ovl26 == 0 && *(s16*)(obj + 0xE) >= 0x1240) {
        D_800FA683_ovl26 = 1;
    }
    if (*(s16*)(obj + 0xE) >= 0x1260) {
        *(s32*)(obj + 0x24) = 0;
        obj[6]++;
        func_800171E8(obj, 8);
        *(s32*)(obj + 0x54) = 0;
        *(s32*)(obj + 0x50) = 0;
    }
}
