#include "types.h"

extern s32 func_800317B8(u8* a0);
extern void func_8002DED4(u8* obj);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F7310_ovl29(u8* obj) {
    func_800317B8(obj);
    func_8002DED4(obj);
    func_80017248(obj);
    if (obj[0x70] & 8) {
        *(s32*)(obj + 0x50) = 0;
        obj[6]++;
        func_800171E8(obj, 0x20);
    }
    func_8002D9EC(obj, 0x30, 0x30);
}
