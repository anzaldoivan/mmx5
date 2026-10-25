#include "types.h"

extern s32 func_800317B8(u8* a0);
extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F72A0_ovl29(u8* obj) {
    u8* sub = *(u8**)(obj + 0x7C);

    func_800317B8(obj);
    func_80017248(obj);
    func_8002D9EC(obj, 0x30, 0x30);
    if (*(s8*)(sub + 5) != 7) {
        obj[5] = 0;
        obj[6] = 0;
        obj[4]++;
    }
}
