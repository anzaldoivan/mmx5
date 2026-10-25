/* Shared body (DK-5), from the banked draft of func_800F0EB8_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A197;
void func_80017248(void);
void func_8002DF54(u8* a0);
s32 func_800317B8(u8* a0);
s32 func_80031DD0(u8* a0);
s32 func_8004FD24(u8* a0);
s32 func_8002F8FC(u8* a0);
s32 func_8004FC64(u8* a0);
s32 func_8002D938(u8* a0, s32 a1, s32 a2);
void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* a0) {
    if (D_8009A197 == 0) {
        func_80017248();
        func_8002DF54(a0);
    }
    if (func_800317B8(a0) != 0) {
        goto store2;
    }
    if (func_80031DD0(a0) < 0) {
        func_8004FD24(a0);
        a0[4] = 2;
    } else {
        *(u16*)(a0 + 0x42) &= 0x7FFF;
    }
    if (a0[0x70] == 0) {
        func_8002F8FC(a0);
        if (a0[0x70] == 0) {
            goto check;
        }
    }
    func_8004FC64(a0);
    a0[4] = 2;
    return;
check:
    if (func_8002D938(a0, 0x20, 0x20) == 0) {
        func_8002D9EC(a0, 0x10, 0x10);
        return;
    }
store2:
    a0[4] = 2;
}
