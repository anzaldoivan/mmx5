#include "types.h"

extern void func_8002A600(s32, s32, s32);
extern s32 func_80016490(s32, s32, void*);
extern s32 func_8002DF78(void);
extern u8* func_8002D27C(void);
extern u16 D_8009A22C;
extern s32 D_8009A420;
extern u8 D_800D1C00[];

void func_800FA1E0_ovl04(u8* obj) {
    u8* spawn;
    s32 r;

    *(s32*)(obj + 0x8) += 0x10000;
    obj[0x8D]++;
    if (*(s16*)(obj + 0xA) < 0x22D && D_8009A22C == 0) {
        func_8002A600(0x10, 3, 2);
    }
    if (*(s16*)(obj + 0xA) >= 0x230) {
        func_80016490(5, 0x14, 0);
        obj[0x5]++;
        D_800D1C00[0x27] = 0;
        D_800D1C00[0x2A] = 0;
        D_800D1C00[0x28] = 0;
        D_800D1C00[0x29] = 0;
        D_800D1C00[0x2B] = 0;
        D_800D1C00[0x26] = 1;
        *(s32*)(obj + 0x84) = 0;
        obj[0x8C] = 0;
        obj[0x8D] = 0xB4;
        obj[0x97] = 0;
        r = func_8002DF78();
        *(s16*)(obj + 0x8A) = 0x28;
        obj[0x91] = 0;
        obj[0x90] = 0;
        *(s16*)(obj + 0x88) = (u8)((u32)r % 50) + 0x28;
    }
    if (!(D_8009A420 & 7) && (func_8002DF78() & 0x10)) {
        spawn = func_8002D27C();
        if (spawn != 0) {
            spawn[0] = 0x41;
            spawn[1] = 0x18;
            spawn[2] = 0;
            *(u8**)(spawn + 0x50) = obj;
        }
    }
}
