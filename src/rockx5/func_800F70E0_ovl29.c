#include "types.h"

extern void func_8002A600(s32, s32, s32);
extern s32 func_800317B8(u8* a0);
extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern s8 D_800D1C0C;

void func_800F70E0_ovl29(u8* arg0) {
    u16 u;
    s16 t;

    t = *(s16*)(arg0 + 0x88);
    u = *(u16*)(arg0 + 0x88);

    if (t >= 2) {
        *(s16*)(arg0 + 0x88) = u - 1;
        return;
    }
    if (t == 1) {
        *(s16*)(arg0 + 0x88) = u - 1;
        func_8002A600(0x78, 4, 2);
    }
    func_800317B8(arg0);
    func_8002DF54(arg0);
    func_80017248(arg0);
    if (D_800D1C0C == 0xC) {
        if (*(s16*)(arg0 + 0xE) >= 0x6C9) {
            func_800171E8(arg0, 0x20);
            *(s16*)(arg0 + 0xE) = 0x6C8;
            arg0[6]++;
        }
    } else if (*(s16*)(arg0 + 0xE) >= 0x2B9) {
        func_800171E8(arg0, 0x20);
        *(s16*)(arg0 + 0xE) = 0x2B8;
        arg0[6]++;
    }
}
