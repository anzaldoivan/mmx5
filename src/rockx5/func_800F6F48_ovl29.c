#include "types.h"

extern void func_800317B8(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);

void func_800F6F48_ovl29(u8* a0) {
    func_800317B8(a0);
    if (--*(s16*)(a0 + 0x88) == 0) {
        *(s32*)(a0 + 0x24) = -*(s32*)(a0 + 0x24);
        *(s16*)(a0 + 0x88) = 7;
    }
    if (func_8002D938(a0, 0x100, 0x100) == 0) {
        func_8002D9EC(a0, 0x30, 0x30);
    } else {
        a0[5] = 0;
        a0[4]++;
    }
    func_8002DF54(a0);
    func_80017248(a0);
}
