/* Shared body (DK-5), from the banked draft of func_800F5DA4_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A197;
void func_80017248(void);
void func_8002DF54(u8* a0);
s32 func_800317B8(u8* a0);
s32 func_8002F8FC(u8* a0);
s32 func_8004FC64(u8* a0);
s32 func_8002D938(u8* a0, s32 a1, s32 a2);
void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* a0) {
    if (D_8009A197 == 0) {
        func_80017248();
        func_8002DF54(a0);
    }
    func_800317B8(a0);
    if (a0[0x70] != 0) {
        goto block;
    }
    func_8002F8FC(a0);
    if (a0[0x70] != 0) {
    block:
        func_8004FC64(a0);
        a0[4]++;
        return;
    }
    if (func_8002D938(a0, 0x20, 0x20) == 0) {
        func_8002D9EC(a0, 0x10, 0x10);
        return;
    }
    a0[4]++;
}
