#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800750C0[];
extern u8 D_800F9964_ovl11[];
extern u8 D_800F9968_ovl11[];

void func_800F2A04_ovl11(u8* obj) {
    *(u8**)(obj + 0x58) = D_800750C0;
    *(u8**)(obj + 0x54) = D_800F9964_ovl11;
    *(u8**)(obj + 0x50) = D_800F9968_ovl11;
    obj[6]++;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    func_800171E8(obj, 8);
}
