#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_800D1C00[];

void func_800F4244_ovl29(u8* obj) {
    if (*(s8*)(obj + 0x46) == 0) {
        func_800171E8(obj, 0x12);
        D_800D1C00[0x24] = 1;
        D_800D1C00[0x25] = 0;
        *(s16*)(obj + 0x7E) = 3;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
