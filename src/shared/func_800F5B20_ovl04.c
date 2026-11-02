/* Shared body (DK-5), from the banked draft of func_800F5B20_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_80074EE0[];
extern u8 D_8009A11A;
extern void* D_80101C0C_ovl04[];

void DEDUP_NAME(u8* arg0) {
    s32 res;

    res = func_80031DD0(arg0);
    if (*(s8*)(arg0 + 0x45) == 0x40) {
        func_80016490(2, 0x81, arg0);
    }
    *(u8**)(arg0 + 0x58) = D_80074EE0;
    if (res < 0) {
        arg0[4] = 2;
        arg0[5] = 0;
        *(u16*)(arg0 + 0x42) &= 0x7FFF;
        D_8009A11A = 1;
        return;
    }
    func_80017248(arg0);
    ((void (*)(u8*))D_80101C0C_ovl04[*(s8*)(arg0 + 7)])(arg0);
    func_800317B8(arg0);
    func_8002D9EC(arg0, 0x80, 0x80);
}
