#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F41DC_ovl29(u8* obj) {
    if (*(s8*)(obj + 0x46) == 0) {
        func_800171E8(obj, 0x11);
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
