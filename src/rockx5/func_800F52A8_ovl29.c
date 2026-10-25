#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800F989C_ovl29[];
extern u8 D_800F9894_ovl29[];

void func_800F52A8_ovl29(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (*(s8*)(obj + 0x45) == 2) {
        *(u8**)(obj + 0x50) = D_800F989C_ovl29;
    }
    if (obj[0x15] != 0 ? *(s32*)(obj + 0x20) < 0 : *(s32*)(obj + 0x20) >= 0) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
    }
    if (*(s32*)(obj + 0x24) < 0) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[6]++;
        func_800171E8(obj, 7);
        *(u8**)(obj + 0x50) = D_800F9894_ovl29;
    }
}
