#include "types.h"

extern u8 D_8009A197;
void func_80017248(void);
void func_8002DF54(u8* a0);
s32 func_800317B8(u8* a0);
s32 func_80031DD0(u8* a0);
s32 func_8002F8FC(u8* a0);
s32 func_8004FD24(u8* a0);
s32 func_8002D938(u8* a0, s32 a1, s32 a2);
void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F5AB4_ovl29(u8* a0) {
    if (D_8009A197 == 0) {
        func_80017248();
        func_8002DF54(a0);
    }
    if (func_800317B8(a0) != 0) {
        a0[4] = 2;
        return;
    }
    if (func_80031DD0(a0) < 0 || a0[0x70] != 0) {
        goto block;
    }
    func_8002F8FC(a0);
    if (a0[0x70] != 0) {
    block:
        func_8004FD24(a0);
        a0[4] = 2;
        return;
    }
    if (func_8002D938(a0, 0x20, 0x20) == 0) {
        func_8002D9EC(a0, 0x10, 0x10);
        return;
    }
    a0[4] = 2;
}
