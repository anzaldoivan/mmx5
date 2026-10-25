#include "types.h"

extern s32 func_800317B8(u8* a0);
extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);
extern s32 func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F7544_ovl29(u8* a0) {
    func_800317B8(a0);
    func_8002DF54(a0);
    func_80017248(a0);
    func_8002D9EC(a0, 0x30, 0x80);
    if (*(s8*)(a0 + 3) == 0) {
        a0[4]++;
        a0[5] = 0;
        a0[6] = 0;
    }
}
