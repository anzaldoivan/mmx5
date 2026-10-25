#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002385C(s32, s32, s32);
extern u8 D_800D1C00[];

void func_800F5520_ovl28(u8* obj) {
    s8 state;
    u8* d;

    func_80017248(obj);
    state = ((s8*)obj)[7];
    if (state == 1) {
        d = D_800D1C00;
        func_8002385C(0x42, 0xFF, d[0x2E]);
        d[0x2E] = state;
        obj[6]++;
    }
}
