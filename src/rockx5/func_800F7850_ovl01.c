#include "types.h"

extern void func_8002DF54(u8* a0);
extern s32 func_8002F8FC(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern s32 func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_800FD2D0_ovl01[];

void func_800F7850_ovl01(u8* a0) {
    func_8002DF54(a0);
    if (a0[0x70] == 0) {
        func_8002F8FC(a0);
        if (a0[0x70] == 0) {
            return;
        }
    }
    func_8004FD24(a0);
    func_8004D4F4(2, D_800FD2D0_ovl01, a0);
    a0[4] = 3;
}
